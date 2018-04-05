#include <stdio.h>
#include <conio.h>

int main()
{
	int i=5, j=10;
	int *ptr;
	int **pptr;
	
	ptr = &i;
	pptr = &ptr;
	*ptr = 3;
	**pptr = 7;
	ptr = &j;
	**pptr = 9;
	
	return 0;
}
