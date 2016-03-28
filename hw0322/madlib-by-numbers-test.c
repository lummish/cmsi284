//madlib-by-numbers-test.c
#include "madlib-by-numbers.h"
#include <assert.h>
#include <string.h>

int main() {
	char str0[] = "";
	char str1[] = "Hello 0 1 2\0";
	char str2[] = "Hello 0 1 2 3\0";
	char* words[] = {"what", "is", "up"};
	char* emptyWords[] = {};

	madlib_by_numbers(str0, 3, words); //Empty string
	madlib_by_numbers(str2, 4, words); //Word count larger than word array
	madlib_by_numbers(str1, 0, emptyWords); //Empty words array
}