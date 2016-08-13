/*************************************************************************
    > File Name: CopyFileStand.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 13 Aug 2016 04:57:31 AM PDT
 ************************************************************************/

#include "apue.h"

int 
main(void)
{
	int c;

	while ((c = getc(stdin)) != EOF)
		if (putc(c, stdout) == EOF) {
			//err_sys("output error");
			printf("output error ~!!!");
			exit(1);
		}

	if (ferror(stdin)) {
		//err_sys("input error");
		printf("input error ~!!!");
		exit(1);
	}

	exit(0);
			
}
