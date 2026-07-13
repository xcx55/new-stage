#include"mystdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
myFILE* myfopen(const char* ss,const char* mode){
int flags=-1;
int fd=-1;
if(strcmp("r",mode)==0){
  flags=O_RDONLY;
  fd=open(ss,O_RDONLY);
}else if(strcmp("w",mode)==0){
  flags=O_WRONLY|O_CREAT|O_TRUNC;
  fd=open(ss,flags);
}else if(strcmp("a",mode)==0){
  flags=O_WRONLY|O_CREAT|O_APPEND;
  fd=open(ss,flags);
}else{
//do other thing!
}
  myFILE* fp=(myFILE*)malloc(sizeof(myFILE));
  if(!fp)
  return NULL;
  fp->fd=fd;
  fp->flags=flags;
  fp->pos=0;
  fp->cap=SIZE;
  //这里应该要执行系统调用  来确定这个要为c语言什么刷新！
  fp->flush_mode=Line_buffer;
  printf("hello!\n");
  return fp;

}

int myfputs(myFILE* fp,const char* s){
  memcpy(fp->outbuffer+fp->pos,s,strlen(s));
  fp->pos+=strlen(s);
printf("%d\n",fp->pos);
  //行刷新
  myfflush(fp);
  return strlen(s);
}

void myfflush(myFILE* fp){
if(fp->pos==0)
return;
	if(fp->flush_mode==Line_buffer){
    if(fp->outbuffer[fp->pos-1]=='\n'){
      write(fp->fd,fp->outbuffer,fp->pos-1);
      fp->pos=0;
    }
  }
else if(fp->flush_mode==Full_buffer){
//逻辑处理 满刷新

  }
else if(fp->flush_mode==None_buffer){
//逻辑处理 空刷新
}

}


void myfclose(myFILE* fp){
  //强制刷新！
  myfflush(fp);
  //关闭文件
  close(fp->fd);

  free(fp);
  fp=NULL;
  return;

}
