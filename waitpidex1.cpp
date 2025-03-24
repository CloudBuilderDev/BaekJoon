
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // 자식 프로세스: 자신보다 더 하위의 프로세스가 없으므로 waitpid() 호출
        int status;
        pid_t result = waitpid(-1, &status, 0);
        if (result == 0) {
            printf("자식 프로세스는 대기할 다른 자식 프로세스가 없습니다.\n");
        } else if (result > 0) {
            printf("대기 중인 자식 프로세스의 PID: %d\n", result);
        }
        return 0;
    } else {
        // 부모 프로세스
        wait(NULL); // 자식이 종료되기를 기다림
        printf("부모: 자식 프로세스 종료됨\n");
    }

    return 0;
}
