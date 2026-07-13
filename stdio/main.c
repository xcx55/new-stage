#include"mystdio.h"

int main(){
  myFILE* fp=myfopen("kk.txt","w");
  int a=5;
  printf("%s\n",fp->outbuffer);
  while(a--){

  int g=myfputs(fp,"LIHAO\n");
  printf("%d\n",g);
  }
  myfclose(fp);
  return 0;
}
