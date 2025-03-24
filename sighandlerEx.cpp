
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// SIGCHLD 핸들러
void sigchld_handler(int sig) {
    int status;
    pid_t pid;

    // 종료된 자식 프로세스 확인
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
        printf("Child process %d terminated.\n", pid);
    }
}

int main() {
    signal(SIGCHLD, sigchld_handler); // SIGCHLD 핸들러 등록

    // 자식 프로세스 생성
    pid_t pid = fork();

    if (pid == 0) {
        // 자식 프로세스: 간단히 종료
        printf("Child process running.\n");
        sleep(2);
        printf("Child process exiting.\n");
        exit(0);
    } else {
        // 부모 프로세스: 대기
        printf("Parent process waiting for child.\n");
        sleep(5);
        printf("Parent process exiting.\n");
    }

    return 0;
}
