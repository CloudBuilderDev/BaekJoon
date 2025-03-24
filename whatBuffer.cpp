
#include <stdio.h>
#include <unistd.h> // sleep() 사용을 위해

int main() {
    printf("Without fflush:");
    sleep(2); // 2초 동안 대기
    printf(" After 2 seconds\n"); // 줄바꿈 추가 시 출력됨

    printf("With fflush:");
    fflush(stdout); // 즉시 출력
    sleep(2); // 2초 동안 대기
    printf(" After 2 seconds\n");

    return 0;
}
