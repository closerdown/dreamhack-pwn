// 해당하는 문제 c언어 코드 파일
// gcc -o baby-bof baby-bof.c -fno-stack-protector -no-pie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

void proc_init ()
{
  setvbuf (stdin, 0, 2, 0); setvbuf (stdout, 0, 2, 0);
  setvbuf (stderr, 0, 2, 0);
}

void win ()         // 플래그 파일 읽어서 출력
{
  char flag[100] = {0,};
  int fd;
  puts ("You mustn't be here! It's a vulnerability!");

  fd = open ("./flag", O_RDONLY);
  read(fd, flag, 0x60);
  puts(flag);
  exit(0);
}

long count;
long value;
long idx = 0;
int main ()
{
  char name[16];

  // don't care this init function
  proc_init (); 

  printf ("the main function doesn't call win function (0x%lx)!\n", win);   // win 함수 주소값

  printf ("name: ");
  scanf ("%15s", name);                //15바이트까지만 입력값 제한
  printf ("GM GA GE GV %s!!\n: ", name);

  printf ("|  addr\t\t|  value\t\t|\n");
  for (idx = 0; idx < 0x10; idx++) {                            
    printf ("|  %lx\t|  %16lx\t|\n", name + idx *8, *(long*)(name + idx*8));       //&name[idx], name[idx]
  }

  /* 
  for (idx = 0; idx <= 15; idx++) {
      print("주소값, 주소에 해당하느 실제값")        -> name에 대한 변수
  }
  */

  printf ("hex value: ");           // 16진수값 입력받음
  scanf ("%lx%c", &value);

  printf ("integer count: ");       // 루프 몇 번 돌지 입력받음  
  scanf ("%d%c", &count);

  // 이 코드에서 count값을 내가 입력하는 방식이라 공간 크기를 제한없이 할당가능(ret로 해당 win함수의 주소가 채워지면 bof 가능)
  for (idx = 0; idx < count; idx++) {          // name[idx]에 순회하면서 scanf로 입력한 16진수를 모든 주소에 채워넣음   
    *(long*)(name+idx*8) = value;         // name[idx] = value
  }
  
  /* 
  for (idx = 0; i < count; idx++) {
     name[idx] = value                            
  }
  */
  
  
  printf ("|  addr\t\t|  value\t\t|\n");
  for (idx = 0; idx < 0x10; idx++) {
    printf ("|  %lx\t|  %16lx\t|\n", name + idx *8, *(long*)(name + idx*8));      //("%lx  %16lx", &name[idx], name[idx]) 
  }
  
  /*
   for (idx = 0; idx <= 15; idx++) {
     print(&name[idx], name[idx])
   }
  
  */




  return 0;
}
