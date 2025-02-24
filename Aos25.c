//  Write a C program which receives file names as command line arguments and display 
// those filenames in ascending order according to their sizes. 
// (e.g $ a.out a.txt b.txt c.txt, …)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
struct filelist {
char fname[100];
int fsize;
};
int main(int argc, char * argv[]) {
DIR *dp;
int i,j=0;
struct dirent *ep;
struct stat sb;
struct filelist f1[100],temp;
if(argc < 2) {
printf("please provide file names as command line arguments.\n");
return 1;
}
dp=opendir("./");
if(dp == NULL) {
perror("unable to open directory");
return 1;
}
while((ep = readdir(dp)) != NULL) {
for(i=1;i<argc;i++) {
if(strcmp(ep->d_name,argv[i]) ==0)
{
if(stat(ep->d_name,&sb) ==0) {
strcpy(f1[j].fname,ep->d_name);
f1[j].fsize=sb.st_size;
j++;
}
}
}
}
closedir(dp);
for(i=0;i<j-1;i++) {
for(int k=i+1;k < j;k++) {
if(f1[i].fsize > f1[k].fsize) {
temp = f1[i];
f1[i] = f1[k];
f1[k] = temp;
}
}
}
printf("files in ascending order of their size:\n");
for(i=0; i<j; i++) {
printf("%s\t%d bytes\n",f1[i].fname,f1[i].fsize);
}
return 0;
}
