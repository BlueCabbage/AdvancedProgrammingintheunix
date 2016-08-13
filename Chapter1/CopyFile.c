/*************************************************************************
    > File Name: CopyFile.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 13 Aug 2016 04:47:30 AM PDT
 ************************************************************************/

#include "apue.h"


#define	BUFFSIZE	4096


int
main (int argc, char *argv[]) 
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
		if (write(STDOUT_FILENO, buf, n) != n ) {
			//err_sys("Write error")
			printf("Write error ~!!");
			exit(1);
		}
	}

	if (n < 0) {
		//err_sys("read error");
		printf("Read error ~!!");
		exit(1);
	}


	exit(0);

}
