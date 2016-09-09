/*************************************************************************
    > File Name: getc_putc.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Thu 08 Sep 2016 11:52:29 PM PDT
 ************************************************************************/
#include "apue.h"

int main(void) 
{
	int c;
	
	while((c = getc(stdin)) != EOF) {
		if (putc(c, stdout) == EOF) {
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
