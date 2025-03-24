
#include <stdio.h>
#include <stdlib.h> // exit() 사용을 위해

int main() {
    printf("Hello, World! "); // 개행 없음
    //exit(1); // '비정상 종료'->  stdout이 터미널과 연결되어 있기에 exit되기 전에 stdout을 닫으며 출력됨
    abort();  // kill이나 abort로 '강제 종료'하면 의도한대로 버퍼를 못 비우고 종료
    return 0; // 정상 종료 -> 출력됨
}
