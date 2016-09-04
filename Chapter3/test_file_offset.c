/*************************************************************************
    > File Name: test_file_offset.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 03 Sep 2016 02:02:32 AM PDT
 ************************************************************************/
#include "apue.h"

int main(void)
{
	if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
		printf("cannot seek\n");
	else
		printf("seek OK\n");


	exit(0);
}
