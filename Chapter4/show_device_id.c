/*************************************************************************
    > File Name: show_device_id.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Wed 07 Sep 2016 02:35:37 AM PDT
 ************************************************************************/
#include "apue.h"

#ifdef SOLARIS
#include <sys/mkdev.h>
#endif

#include <sys/sysmacros.h>

int main(int argc, char *argv[])
{
	int i;
	struct stat buf;
	
	for (i = 1; i < argc; i ++) { 
		printf("%s: ", argv[i]);
		if (stat(argv[i], &buf) < 0) {
			printf("stat error.");
			continue;
		}

		printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));
		if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode)) {
			printf(" (%s) rdev = %d/%d", (S_ISCHR(buf.st_mode)) ? "charater" : "block", major(buf.st_rdev), minor(buf.st_rdev));
		}

		printf("\n");
	}

	exit(0);

}
