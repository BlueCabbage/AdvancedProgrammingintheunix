/*************************************************************************
    > File Name: create_a_file_with_null_hole.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Sat 03 Sep 2016 02:06:30 AM PDT
 ************************************************************************/
#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int fd;

	if ((fd = creat("file.hole", FILE_MODE)) < 0) {
		printf("create error");
		exit(0);
	}

	if (write(fd, buf1, 10) != 10) {
		printf("buf1 write error");
		exit(0);
	}
	
	/* offset now = 10 */

	if (lseek(fd, 16384, SEEK_SET) == -1) {
		printf("lseek error");
		exit(0);
	}

	/* offset now = 16394 */

	if (write(fd, buf2, 10) != 10) {
		printf("buf2 write error");
		exit(0);
	}


	exit(0);
}
