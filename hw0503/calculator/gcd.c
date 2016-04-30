//gcd.c
#include <stdio.h>

int gcd(int x, int y);

int main(int argc, char *argv[])
{
	if (argc != 3) {
		puts("Argument error.");
	} else {
		int x = atoi(argv[1]);
		int y = atoi(argv[2]);
		int denom = gcd(x, y);
		printf("%d\n", denom);
		return denom;
	}
	return 0;
}