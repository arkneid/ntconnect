// includes
#include "functions.h"
#include <stdlib.h>
/***********************/

int nc_strcmp(const char* s1, const char* s2)
{
	int i;

	i = 0;
	while(s1[i] != '\0' && s2[i] != '\0')
	{
		if(s1[i] != s2[i])
		{
			if(nc_strlen(s1) > nc_strlen(s2))
				return 1;
			else if(nc_strlen(s2) > nc_strlen(s1))
				return -1;
			else
				return 2;
		}
		i++;
	}
	return 0;
}

int nc_strlen(const char* str)
{
	int size;

	size = 0;	
	while(str[size] != '\0')
	{
		size++;
	}	

	return size;
}

char* nc_strcpy(char* dst, const char* src)
{
	int i;
	int s_src;

	s_src = nc_strlen(src);
	dst = (char*)malloc(s_src + 1);
	i = 0;
	while(i <= s_src)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	
	return dst;
}
