/*************************************************************************
    > File Name: getpwnam.c
    > Author: ZHAOCHAO
    > Mail: 479680168@qq.com 
    > Created Time: Fri 09 Sep 2016 06:06:39 AM PDT
 ************************************************************************/
#include <pwd.h>
#include <stddef.h>
#include <string.h>


struct passwd * getpwnam(const char *name)
{
	struct passwd *ptr;

	setpwent();
	while((ptr = getpwent()) != NULL) {
		if (strcmp(name, ptr->pw_name) == 0)
			break;	/* found a match */
	}

	endpwent();
	
	return ptr;
}
