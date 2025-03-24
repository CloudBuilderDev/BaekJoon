#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

pid_t pid;
int counter = 2;

void handler1(int sig) {
    counter = counter - 1;
    printf("%d", counter);
    fflush(stdout);
    exit(0);
}

int main() {
    signal(SIGUSR1, handler1);

    printf("%d", counter); // 버퍼에 counter를 넣기
    fflush(stdout);  // 버퍼를 출력

    if ((pid = fork()) == 0) {
        while (1) {}  // 자식 프로세스가 무한 대기
    }

    kill(pid, SIGUSR1);  // 자식의 counter -1 후 출력 후 자식 종료
    waitpid(-1, NULL, 0);  // 자식이 종료할 때까지 대기 중
    counter = counter + 1;  // 부모 counter + 1 = 3
    printf("%d", counter);
    exit(0);
}
