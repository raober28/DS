#include"util.h"


long decimalToBinary(int n);

long decimalToBinary(int n)
{	
	int r, i = 0;
	long b;

	char arr[100]; 
	while(n)
	{
		r = n % 2;
		arr[i] = r + '0';
		n = n / 2;
		i++;
	}

	arr[i] = '\0';

	reverse_str(arr);

	b = itoa(arr);
	return b;

}


int main(int argc, char const *argv[])
{	
	int n = 100;
	long b = decimalToBinary(n);

	printf("Binary equivalent of %d is: %ld\n", n, b);
	return 0;
}




