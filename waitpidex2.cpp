
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // 자식 프로세스
        sleep(3);
        return 0;
    } else {
        // 부모 프로세스
        int status;

        // 기본 동작
        pid_t result = waitpid(-1, &status, 0);
        if (result > 0) {
            printf("자식 종료, PID: %d\n", result);
        }

        // WNOHANG 사용
        result = waitpid(-1, &status, WNOHANG);
        if (result == 0) {
            printf("WNOHANG: 자식 프로세스가 아직 종료되지 않음\n");
        } else if (result > 0) {
            printf("WNOHANG: 자식 종료, PID: %d\n", result);
        }

        // WUNTRACED 사용
        result = waitpid(-1, &status, WUNTRACED);
        if (result > 0 && WIFSTOPPED(status)) {
            printf("WUNTRACED: 자식 프로세스 중지 상태, PID: %d\n", result);
        }

        // WCONTINUED 사용
        result = waitpid(-1, &status, WCONTINUED);
        if (result > 0 && WIFCONTINUED(status)) {
            printf("WCONTINUED: 자식 프로세스 재개 상태, PID: %d\n", result);
        }
    }
    return 0;
}