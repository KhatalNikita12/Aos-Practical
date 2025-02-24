// Write a C program to find file properties such as inode number, number of hard link, File 
// permissions, File size, File access and modification time and so on of a given file using 
// fstat() system call. 

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc,int **argv){
int file=0;
struct stat info;
if(argc!=2){
printf("usage :%s <Filename>\n ",argv[0]);
return 1;

}
if((file=open(argv[1],O_RDONLY))==-1){
perror("Error opening file");
return 1;
}
if(fstat(file,&info)<0){
perror("Error getting file stats");
return 1;
}
printf("Information for %s\n",argv[1]);
printf("file inode number::%ld\n",(long)info.st_ino);
printf("file size::%lld Bytes\n",(long long)info.st_size);
printf("Last file access ::%s",ctime(&info.st_atime));
printf("Last file modification ::%s",ctime(&info.st_mtime));
printf("Number of hard links ::%ld\n ",info.st_nlink);

printf("file permission");
printf((S_ISDIR(info.st_mode))?"d":"-");
printf((info.st_mode & S_IRUSR)?"r":"_");
printf((info.st_mode & S_IWUSR)?"w":"_");
printf((info.st_mode & S_IXUSR)?"x":"_");
printf((info.st_mode & S_IRGRP)?"r":"_");
printf((info.st_mode & S_IWGRP)?"w":"_");
printf((info.st_mode & S_IXGRP)?"x":"_");
printf((info.st_mode & S_IROTH)?"r":"_");
printf((info.st_mode & S_IWOTH)?"w":"_");
printf((info.st_mode & S_IXOTH)?"x":"_");
printf("\n");
close(file);
return 0;
}