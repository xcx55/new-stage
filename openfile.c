#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
//int main(){
//  char buffer[1024];
//  ssize_t n=open("kk.txt",O_RDONLY);
//  ssize_t nn=read(n,buffer,sizeof(buffer)-1);
//  if(nn>0){
//    buffer[nn]=0;
//    printf("读取正确！\n");
//  }
//  else if(nn==0){
//    perror("open");
//  }
//  else{
//
//  }
//
//
//  return 0;
//}
int main(){
  close(1);
  FILE* fd=fopen("kk.txt","w+");
  printf("hahahahaha");
printf("\n");
  printf("hahahahaha");
  printf("hahahahaha");
    printf("hahahahaha");
    fflush(stdout);
    close(fd->_fileno);
  fputs("hahaha",fd);

  return 0;
}
