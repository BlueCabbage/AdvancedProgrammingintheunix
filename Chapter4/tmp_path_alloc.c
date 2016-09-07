/*************************************************************************
    > File Name: tmp_path_alloc.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Wed 07 Sep 2016 02:25:13 AM PDT
 ************************************************************************/

#include "apue.h"

char *path_alloc(size_t * size)
{
	char *p = NULL;
	if (!size)
		return NULL;

	p = malloc(256);

	if (p)
		*size = 256;
	else
		*size = 0;

	return p;
}
