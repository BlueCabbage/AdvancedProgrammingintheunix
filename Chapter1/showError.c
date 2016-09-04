/*************************************************************************
    > File Name: showError.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 13 Aug 2016 07:25:17 AM PDT
 ************************************************************************/

#include "apue.h"
#include <errno.h>

int 
main(int argc, char *argv[])
{
	fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
	errno = ENOENT;
	perror(argv[0]);

	exit(0);
}
