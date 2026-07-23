#include<unistd.h>
#include<wait.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#define MAX_SIZE 128
char* gargv[128];
int gargc=1;
const char* gsep = " ";
char cwd[MAX_SIZE];
int exit_cod=0;
//以上就是命令行参数和命令行参数表！！！

const char* GetUserName(){
  char* name=getenv("USER");
  if(name==NULL){
    return "NONE";
  }
  return name;

}
const char* GetHostName(){
  char* host=getenv("HOSTNAME");
  if(host==NULL)
    return "NONE";
  return host;
}

const char* GetPwd(){
char* Pwd=getcwd(cwd,sizeof(cwd));
if(Pwd==NULL){
return "NONE";
}
return cwd;
}

int IsBuiltinCommand(){
  if(strcmp(gargv[0], "cd")==0){
    if(gargc==2){
  chdir(gargv[1]);
  getcwd(cwd,sizeof(cwd));
  putenv(cwd);
return 1;
  }

  }
  if(strcmp(gargv[0],"echo")==0&&strcmp(gargv[1],"$PATH")==0){
    printf("%s\n",getenv("PATH"));
    return 1;
  }

  if(strcmp(gargv[0],"echo")==0&&strcmp(gargv[1],"$CWD")==0){
    printf("%s\n",getenv("CWD"));
  }
  if(0==strcmp(gargv[0],"echo")){
    if(gargc==2&&strcmp(gargv[1],"$?")==0){
      printf("%d\n",exit_cod);
    }
    else if(gargc==2&&strcmp(gargv[1],"$?")!=0){
      printf("%s\n",gargv[1]);
    }
    return 1;
  }
  return 0;
}

void Parse_command_line(char Command_line[]){
  memset(gargv,0,MAX_SIZE*sizeof(char*));
  gargc=0;
  gargv[0]=strtok(Command_line,gsep);
  while(gargv[++gargc]=strtok(NULL,gsep));
  //int i=0;
  //for(;gargv[i];i++){
  //  printf("%s ",gargv[i]);
  //}
}


void PrintCommendLine(){
  printf("[%s@%s %s]#",GetUserName(),GetHostName(),GetPwd());//用户名  主机名  当前路径
  fflush(stdout);
}

int Getcommand_line(char Command_line[],int size){

  fgets(Command_line,sizeof(char)*MAX_SIZE,stdin);
  if(Command_line[0]=='\0')
    return 0;
  Command_line[strlen(Command_line)-1]='\0';

  return 1;
}
int ExecuteCommand(){
  pid_t id=fork();
  if(id<0){
//child
    return -1;
  }
  else if(id==0){
    //child
    execvp(gargv[0],gargv);
    exit(1);
  }
  else{
    //parent
    int status=0;
    pid_t rid=waitpid(id,&status,0);
    if(rid>0){
      //printf("wait success!!\n");
      exit_cod=(status>>8)&0xFF;
    }
  }
  return 0;
}


int main(){
  char Command_line[MAX_SIZE]={'\0'};
  while(1){
    PrintCommendLine();
    if(0==Getcommand_line(Command_line,strlen(Command_line))){
      continue;
    }
    //printf("%s",Command_line);
    Parse_command_line(Command_line);//解析命令
    //执行命令！
    if(IsBuiltinCommand()){
      continue;
    }
    ExecuteCommand();

    fflush(stdout);
    
  }
  return 0;
}
