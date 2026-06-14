#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    if (chdir("/home/xcx") == -1) {
    perror("chdir failed");
    return 1;
}
  while(1){

    printf("我是一个进程(fork) pid:%d ppid:%d\n",getpid(),getppid());
    sleep(1);
  }

 return 0;
}
