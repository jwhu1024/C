#include <sys/syscall.h> 
#include <linux/unistd.h>

pid_t gettid()
{
    return syscall(SYS_gettid);
}