#include <stdio.h>
#include <unistd.h>

void get_shell() {                   //쉘을 실행하는 구현함수
  .....
}

int main() {
  char buf[0x28];        // buf[40]        
 
  scanf("%s", buf);                // 입력받을 시, scanf같은 경우. 주소값을 넣을 시 수만큼 입력가능 
}
