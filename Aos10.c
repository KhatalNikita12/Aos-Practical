// Write a C program to create a file with hole in it. 
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
char b1[]="Welcome";
char b2[]="computer science";

int main(){
int fd;
if((fd=creat("file_with_hole.txt",0777))<0)
{
printf("create error");
}
if(write(fd,b1,7)!=7)
printf("b1 write error");
lseek(fd,500,SEEK_CUR);
if(write(fd,b2,16)!=16)
printf("b2 write error");
exit(0);
}