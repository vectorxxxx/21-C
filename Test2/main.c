#include <stdio.h>

int main(int argc, char** argv) {
	int a=7, b;
	b = a++;
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	
	return 0;
}
