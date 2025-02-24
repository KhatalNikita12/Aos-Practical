// Write a C program to move the content of file1.txt to file2.txt and remove the file1.txt 
// from directory

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#define buffsize 10000
int main()
{
char sour[25],dest[25],buff[buffsize];
ssize_t read_in,write_out;
printf("\n Enter source file name");
scanf("%s",sour);
printf("\n Source file ::%s",sour);
int rfp=open(sour,O_RDONLY);
if(rfp<0){
printf("\nSource file does not exist.\n");
return 1;
}
printf("\nEnter designation file name:");
scanf("%s",dest);
int wfp=open(dest,O_WRONLY | O_CREAT | O_APPEND,0644);
if(wfp<0)
{
printf("\n Unable to open designation file.\n");
close(wfp);
return 1;
}
while((read_in=read(rfp,buff,buffsize))>0)
{
write_out=write(wfp,buff,read_in);
if(write_out!=read_in)
{
printf("\nError writing to the designation file\n ");
close(rfp);
close(wfp);
return 1;
}
}
close(rfp);
close(wfp);
if(remove(sour)==0)
{
printf("\n file deleted successfully\n");

}
else

{
printf("\n Unable to delete the source file.\n");
}
return 0;

}
