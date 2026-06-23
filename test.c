#include<stdio.h>
#include<iostream>
#include<vector>
#include<sys/types.h>
#include<wait.h>
#include<unistd.h>
#include<stdlib.h>

class Task{
  public:
    void operator()(){
      printf("hahaha\n");
    }
};

void CreatChildProcess(int a,std::vector<pid_t>* con){
  int b=0;
  for(;b<a;b++){
    pid_t id=fork();
    if(id==0){
      //child
     Task()();
    //  std::cout<<std::endl;
    //  std::cout<<"hahaha,我是第"<<b<<"个子进程！"<<std::endl;
    //  std::cout<<std::endl;
      sleep(1);
      //con->push_back(getpid());//等一会试一下引用怎么样！
      exit(0);
    }
    else if(id>0){
      con->push_back(id);
    }
  }
}
void WaitChildProcess(int a,std::vector<pid_t>* con){
  int status=0;
  for(auto& x:(*con)){
    pid_t rid=waitpid(x,&status,0);
    if(rid>0){
      std::cout<<"我是pid为"<<x<<"的进程，我成功被回收了，我的exit_cod="<<((status>>8)&0xFF)<<"我的exit_sig="<<(status&0x7F)<<std::endl;
    }else{
      std::cout<<"进程"<<x<<"回收失败"<<std::endl;
      exit(0);
    }
  }
}



int main(){
  std::vector<pid_t> _con;
  CreatChildProcess(5,&_con);
  WaitChildProcess(5,&_con);
  return 0;
}
