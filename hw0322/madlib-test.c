//madlib-test.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "madlib.h"

int main(int argc, char const *argv[])
{
	char* test1 = madlib("Not enough %s %s", "one", "two", "three");
	char* test2 = madlib("Just fine %s %s %s", "one", "two", "three");
	char* test3 = madlib("Number specifiers %d %d %d", "one", "two", "three");
	//char* test4 = madlib("Non string inputs %s %s %s", 1, 2, 3);

	assert(strlen(test1) == 0);
	assert(strncmp(test2, "Just fine one two three", strlen(test2)) == 0);
	assert(strlen(test3) == 0);
	//assert(strncmp(test4, "Non string inputs 1 2 3", strlen(test4)));
	//assert(strncmp(test, ,));
	//assert(strncmp(test, ,));
	return 0;
}