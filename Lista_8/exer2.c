#include <stdio.h>

void linha(int);

void main()
{	linha(3);
	linha(5);
	linha(7);
	linha(5);
	linha(3);
}

void linha(int i)
{
	for(i; i>0; i--){
		printf("%c", '*');
	}
	printf("\n");
}
