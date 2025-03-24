#include <stdio.h>
#include <sched.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        //sleep(5); // 자식 프로세스가 5초 동안 대기 후 종료
        return 0;
    }
    else
    {
        int status;
        while (1)
        {
            pid_t result = waitpid(pid, &status, WNOHANG);
            if (result == 0)
            {
                printf("자식 프로세스가 아직 종료되지 않았습니다.\n");
            }
            else if (result > 0)
            {
                printf("자식 프로세스 종료됨.\n");
                break;
            }
            sleep(1); // 1초 간격으로 상태 확인
        }
    }
}