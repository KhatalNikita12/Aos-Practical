// Write a C program to map a given file in memory and display the contain of mapped 
// file in reverse. 
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc,char *argv[]){
  if(argc!=2){
    fprintf(stderr,"Usage:%s<Filename>\n",argv[0]);
    return 1;
  }
  int fd=open(argv[1],O_RDONLY);
  if(fd==-1){
    perror("Error opening file");
    return 1;
  }
  stuct stat file_stat;
  if(fstat(fd,&file_stat)==-1){
    perror("Error getting file size");
    close(fd);
    return 1;
  }
  off_t file_size=file_size.st_size;
  char *mapped_file=mmap(NULL,file_size,PROT_READ,MAP_PRIVATE,fd,0);
  if(mapped_file==MAP_FAILED){
    perror("Error mapping file to memory");
    close(fd);
    return 1;
  }
  close(fd);
  for(off_t i=file_size-1;i>=0;i--){
    putchar(mapped_file[i]);
  }
  if(munmap(mapped_file,file_size)==-1){
    perror("error unmapping file from memory");
    return 1;
  }
  return 0;
}
