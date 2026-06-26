#include<stdio.h>

int main(int argc,char* argv[]){
  if(argv[1]=="l")
    printf("这个命令行参数是l!\n");
  else
    printf("没有命令行参数\n");
  return 0;
}
