#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cerrno>

void handler1(int sig)
{
    int olderrno = errno; // 현재 errno 저장
    if ((waitpid(-1, NULL, 0)) < 0)
    {
        write(STDOUT_FILENO, "waitpid error\n", 14); // 에러 메시지 출력
    }
    write(STDOUT_FILENO, "Handler reaped child\n", 22); // 자식 처리 메시지
    sleep(1);                                           // 1초 대기 (주의: 이로 인해 재진입 문제가 발생)
    errno = olderrno;                                   // 기존 errno 복원
}

void handler2(int sig) {
    int olderrno = errno;

    while(waitpid(-1, NULL, 0) > 0) {  // option을 달리하면? ex) WNOHANG
        printf("Handler repead child \n");
    }
    if (errno != ECHILD) {
        printf("waitpid error");
    }
    sleep(1);
    errno = olderrno;
    
}
int main()
{
    int i, n;

    if (signal(SIGCHLD, handler2) == SIG_ERR)
        printf("signal error"); // SIGCHLD 핸들러 등록 실패 시 에러 출력

    for (i = 0; i < 3; i++)
    {
        if (fork() == 0)
        {                                                   // 자식 프로세스 생성
            printf("Hello from child %d\n", (int)getpid()); // 자식 프로세스 메시지 출력
            exit(0);                                        // 자식 프로세스 종료
        }
    }

    printf("Parent processing input\n"); // 부모 프로세스 메시지 출력
    while (1)
        ; // 무한 루프
    exit(0);
}