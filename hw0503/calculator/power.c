//power.c
#include <stdio.h>

int power(int x, int y);

int main(int argc, char const *argv[])
{
	if (argc != 3) {
		puts("Argument error.");
	}
	else {
		int x = atoi(argv[1]);
		int y = atoi(argv[2]);
		if (y < 0) {
			puts("Power cannot be negative.");
			return 0;
		}
		int powx = power(x, y);
		printf("%d\n", powx);
		return powx;
	}
	return 0;
}