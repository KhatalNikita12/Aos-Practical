// Write a C program to read all txt files (that is files that ends with .txt) in the current 
// directory and merge them all to one txt file and returns a file descriptor for the new file
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
int main(){
int in,out;
size_t bread,bwrite;
char buff[100];
char *txt=".txt";
struct dirent *d;
DIR *dir=opendir(".");
if(dir==NULL){
printf("\n Can't open current directory");
return 0;
}
out=open("output.txt",O_WRONLY | O_CREAT | O_APPEND,0644);
if(out==-1)
{
printf("\nError openinng output.txt file.");
closedir(dir);
return 0;
}
while((d=readdir(dir))!=NULL)
{
char *fn=d->d_name;
char *ext=strrchr(fn,'.');
if(strcmp(fn,"output.txt")==0)
continue;
if(ext && strcmp(ext,txt)==0){
in=open(fn,O_RDONLY);
if(in ==-1){
printf("\n error opening file %s",fn);
continue;
}
while((bread=read(in,buff,sizeof(buff)))>0)
{
bwrite=write(out,buff,bread);
if(bread!=bwrite){
perror("Error writting to output file");
}
}
close(in);
}
}
closedir(dir);
close(out);
printf("\n successsfully copied content of all.txt file into output.txt file");
return 0;
}