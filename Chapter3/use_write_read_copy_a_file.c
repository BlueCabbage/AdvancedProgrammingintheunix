/*************************************************************************
    > File Name: user_write_read_copy_a_file.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 03 Sep 2016 02:20:18 AM PDT
 ************************************************************************/
#include "apue.h"

#define BUFFSIZE		4096

int main(void) 
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
		if (write(STDOUT_FILENO, buf, n) != n) {
			printf("write error.");
			exit(0);
		}
	}

	if (n < 0) {
		printf("read error.");
		exit(0);
	}


	exit(0);
}
