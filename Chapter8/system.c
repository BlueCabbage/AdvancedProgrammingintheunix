/*************************************************************************
    > File Name: system.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 11 Sep 2016 01:20:40 AM PDT
 ************************************************************************/
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

int system(const char *cmdstring) /* version without signal handling */
{
	pid_t pid;
	int status;

	if (cmdstring == NULL) {
		return(1); /* always a command processor with UNIX */
	}

	if ((pid = fork()) < 0) {
		status = -1; /* probably out of processes */
	}
	else if (pid == 0) {
		/* child */
		execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
		_exit(127); /* execl error */
	}
	else {
		while (waitpid(pid, &status, 0) < 0) {
			if (errno != EINTR) {
				status = -1; /* error other than EINTR from waitpit() */
				break;
			}
		}
	}


	return(status);
}
