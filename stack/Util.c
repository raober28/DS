#include "util.h"

void printArray(int array[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%s%d %s", (i == 0)?"[":"", array[i], (n -1 == i)?"]":",");

	printf("\n");
}