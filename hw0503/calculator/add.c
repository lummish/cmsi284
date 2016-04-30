#include <stdio.h>
int add(int x, int y);
int	gcd(int x, int y);
int power(int x, int y);

int main(int argc, char* argv[]) {
	if (argc != 3) {
		puts("Argument error.");//throw argument error
		return 0;
	}
	else {
		int x = atoi(argv[1]); //may need to change argument numbers
		int y = atoi(argv[2]);
		int sum = add(x, y);
		printf("%d\n", sum); 
	}

	return 0;
}