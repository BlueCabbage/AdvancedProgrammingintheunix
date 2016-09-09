/*************************************************************************
    > File Name: fgetc_fputc.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Thu 08 Sep 2016 11:55:15 PM PDT
 ************************************************************************/
#include "apue.h"

int main(void)
{
	char buf[MAXLINE];

	while( fgets(buf, MAXLINE, stdin) != NULL) {
		if (fputs(buf, stdout) == EOF) {
			printf("output error~!");
			exit(0);
		}
	}

	if (ferror(stdin)) {
		printf("input error~!");
		exit(0);
	}


	exit(0);
}
