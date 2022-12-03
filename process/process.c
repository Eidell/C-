#include "process.h"

void processon()
{
  int cnt = 0;
  char bar[NUM];
  memset(bar,'\0',sizeof(bar));
  //101次
  char * lable = "|\\-/";
  char style[] = "=-.#";
  while(cnt <= 100)
  {
    printf("[%-100s][%d%%][%c]\r",bar,cnt,lable[cnt%4]);
    fflush(stdout);
    bar[cnt++] = style[N];
    //sleep(1);
    usleep(50000);

  }
  printf("\n");
}
