// Write a C program to find file properties such as inode number, number of hard link, File 
// permissions, File size, File access and modification time and so on of a given file using 
// stat() system call. 

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
#include<string.h>
int main(int argc, char **argv)
{
struct stat info;
if(argc!=2)
{
printf("Enter the file name");

}
printf("arg=%s",argv[1]);
if(stat("aos8.c",&info)==-1){
printf("stat error");
exit(EXIT_FAILURE);
}
printf("I-node number::%1d\n",(long)info.st_ino);
printf("file size::%11d Bytes\n",(long long)info.st_size);
printf("Last File access::%s\n",ctime(&info.st_atime));
printf("Last File modification::%s\n",ctime(&info.st_mtime));
printf("No of Hard Link::%1d\n",info.st_nlink);
printf("File permission::\t");
printf((info.st_mode & S_IRUSR)? "r":"-");
printf((info.st_mode & S_IWUSR)? "r":"-");
printf((info.st_mode & S_IXUSR)? "r":"-");
printf((info.st_mode & S_IRGRP)? "r":"-");
printf((info.st_mode & S_IWGRP)? "r":"-");
printf((info.st_mode & S_IXGRP)? "r":"-");
printf((info.st_mode & S_IROTH)? "r":"-");
printf((info.st_mode & S_IWOTH)? "r":"-");
printf((info.st_mode & S_IXOTH)? "r":"-");
putchar('\n');
}