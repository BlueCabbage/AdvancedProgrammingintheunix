/*************************************************************************
    > File Name: show_current_work_directory.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Wed 07 Sep 2016 02:02:31 AM PDT
 ************************************************************************/
#include "apue.h"

int main(void)
{
	char *ptr;
	size_t size;

	if (chdir("/home/zhaochao/Desktop") < 0) {
		printf("chdir failed.");
		exit(0);
	}

	ptr = path_alloc(&size); /* our own function */
	
	if (getcwd(ptr, size) == NULL ) {
		printf("getcwd failed~!");
		exit(0);
	}

	printf("cwd = %s\n", ptr);


	exit(0);
}
