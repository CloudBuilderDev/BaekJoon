
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define N 2  // 생성할 자식 프로세스의 수


// 이 프로그램은 자식들을 아무런 순서 없이 청소한다는 점에 주목해라 p719
int main() {
    int status, i;
    pid_t pid;

    /* Parent creates N children */
    for (i = 0; i < N; i++) {
        if ((pid = fork()) == 0) {  // 자식 프로세스 생성
            exit(100 + i);          // 자식 프로세스 종료 코드 설정
        }
    }

    /* Parent reaps N children in no particular order */
    while ((pid = waitpid(-1, &status, 0)) > 0) {  // 모든 자식 프로세스를 회수
        if (WIFEXITED(status)) {  // 자식 프로세스가 정상 종료된 경우
            printf("child %d terminated normally with exit status=%d\n",
                   pid, WEXITSTATUS(status));  // 종료 코드 출력
        } else {
            printf("child %d terminated abnormally\n", pid);  // 비정상 종료 처리
        }
    }

    /* The only normal termination is if there are no more children */
    if (errno != ECHILD) {  // 더 이상 자식 프로세스가 없지 않으면 오류 처리
        perror("waitpid error");
    }

    exit(0);
}
