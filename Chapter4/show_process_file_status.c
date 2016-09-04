/*************************************************************************
    > File Name: show_process_file_status.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sun 04 Sep 2016 01:13:16 AM PDT
 ************************************************************************/
#include "apue.h"
#include <fcntl.h>

int main(int argc, char * argv[])
{
	if (argc != 2) {
		printf("usage: app.out <pathname>");
		exit(0);
	}

	if (access(argv[1], R_OK) < 0) {
		printf("read error for %s \n", argv[1]);
	}
	else {
		printf("read access OK\n");
	}

	if (access(argv[1], O_RDONLY) < 0) 
		printf("open error for %s\n", argv[1]);
	else
		printf("open for reading OK\n");


	exit(0);
}
