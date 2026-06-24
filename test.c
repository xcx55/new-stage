#include<stdio.h>
#include<iostream>
#include<wait.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
  int status=0;
  printf("现在是当前一个的子进程\n");
  execl("/usr/bin/ls","-l","-a",NULL);
  printf("hahahaha\n");
  return 0;
}
