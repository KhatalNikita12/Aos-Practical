// Write a C program to create an unnamed pipe. The child process will write following 
// three messages to pipe and parent process display it. 
// Message1 = “Hello World” 
// Message2 = “Hello SPPU” 
// Message3 = “Linux is Funny”
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
int fds[2];
int returnstatus;
char writemsgs[3][20]={"Hello World","Hello SPPU","Linux is Funny"};
char readmsg[20];
returnstatus=pipe(fds);
if(returnstatus==-1){
printf("Unable to create file..\n");
return 1;
}
int child =fork();
if(child ==0){
printf("child is writting to pipe-message1 is %s \n",writemsgs[0]);
write(fds[1],writemsgs[0],sizeof(writemsgs[0]));

printf("child is writting to pipe-message2 is %s \n",writemsgs[1]);
write(fds[1],writemsgs[1],sizeof(writemsgs[1]));

printf("child is writting to pipe-message3 is %s \n",writemsgs[2]);
write(fds[1],writemsgs[2],sizeof(writemsgs[2]));
close(fds[1]);
}
else{
wait(NULL);
read(fds[0],readmsg,sizeof(readmsg));
printf("parent process is reading from pipe- message1 is %s \n",readmsg);
read(fds[0],readmsg,sizeof(readmsg));
printf("parent process is reading from pipe- message2 is %s \n",readmsg);
read(fds[0],readmsg,sizeof(readmsg));
printf("parent process is reading from pipe- message3 is %s \n",readmsg);
close(fds[0]);
}
return 0;
}
