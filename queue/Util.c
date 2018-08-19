#include "util.h"



long reverse(long n)
{
	int r;
	long s = 0;

	while(n)
	{
		r = n % 10;
		s = s * 10 + r;
		n = n / 10;
	}

	return s;
}

void reverse_str(char *s)
{
	int l = length(s), i = 0, temp;
	l--;

	while(i < l)
	{	
		temp = s[i];
		s[i] = s[l];
		s[l] = temp;
		i++;
		l--;
	}
}

int length(char *s)
{
	int n = 0;

	while(*s)
	{
		n++;
		s++;
	}

	return n;

}

long itoa(char *s)
{
	long n = 0;

	while(*s)
	{	
		if(!isNumber(*s))
			printf("warning: not a valid string to parse a number");
		else
			n = n * 10 + (*s - '0');

		s++;
	}
	return n; 
}

int isNumber(char c)
{
	return (c >= '0' && c <= '9');
}