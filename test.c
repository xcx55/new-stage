#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<wait.h>
//int main(){
 // printf("I'm a process\n");
//  sleep(1);
//  //return 0;
//  exit(123);
//}

int main(){
  pid_t id=fork();
  if(id==0){
    while(1){
  sleep(1);
  printf("我是一个子进程！ pid=%d\n",getpid());
    }
  exit(10);
  }
  else{
    printf("我是一个父进程！pid=%d\n",getpid());
    int status=0;
    pid_t rid=waitpid(-1,&status,0);
    if(rid==id){
      printf("等待子进程死亡成功！子进程的信息,exit_sig=%d,exit_cod=%d\n",status&0x7F,(status>>8)&0xFF);
    }
  }
  return 0;
}
