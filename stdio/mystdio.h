#pragma once 
#include<stdio.h>
#define SIZE 1024
#define None_buffer 1//01
#define Line_buffer 2//10
#define Full_buffer 4//100
#include<string.h>


typedef struct _myFILE{
 int fd;
 int flush_mode;
 int flags;
 char outbuffer[SIZE];
 int pos;
 int cap;
}myFILE;

myFILE* myfopen(const char* ss,const char* mode);
void myfclose(myFILE* fp);
int myfputs(myFILE*fp,const char* s);
void myfflush(myFILE* fp);
