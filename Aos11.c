// 11 Write a C program to get and set the resource limits such as files, memory associated 
// with a process.

#include <stdio.h>
#include <sys/resource.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() 
{
    struct rlimit old_lim, lim, new_lim;

    if (getrlimit(RLIMIT_NOFILE, &old_lim) == 0) 
    {
        printf("Old limit -> soft limit: %ld\t hard limit: %ld\n", old_lim.rlim_cur, old_lim.rlim_max);
    } 
    else 
    {
        fprintf(stderr, "%s\n", strerror(errno));
    }

    lim.rlim_cur = 3;
    lim.rlim_max = 1024;
    
    if (setrlimit(RLIMIT_NOFILE, &lim) == -1) 
    {
        fprintf(stderr, "%s\n", strerror(errno));
    }

    if (getrlimit(RLIMIT_NOFILE, &new_lim) == 0) 
    {
        printf("New limit -> soft limit: %ld\t hard limit: %ld\n", new_lim.rlim_cur, new_lim.rlim_max);
    } 
    else 
    {
        fprintf(stderr, "%s\n", strerror(errno));
    }
    
    return 0;
}
