//madlib-by-numbers-test.c
#include "madlib-by-numbers.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

int main() {
	char str0[] = "";
	char str1[] = "Hello 0 1 1 1";
	char str2[] = "Hello 0 1 2 3";
	char* words[] = {"what", "is", "up"};
	char* empty_words[] = {};
	char* words_has_empty_string[] = {"empty", ""};

	char* test0 = madlib_by_numbers(str0, 3, words); //empty template
	char* test1 = madlib_by_numbers(str1, 3, words); //multiple calls to same index
	char* test2 = madlib_by_numbers(str2, 3, words); //index greater than number of words
	char* test3 = madlib_by_numbers(str1, 2, words_has_empty_string);
	char* test4 = madlib_by_numbers(str1, 0, empty_words);

	assert(strncmp(test0, "", strlen(str0)) == 0); //Empty string
	assert(strncmp(test1, "Hello what is is is", strlen(test1)) == 0);
	assert(strncmp(test2, "Hello what is up 3", strlen(test2)) == 0); //Index larger than word array
	assert(strncmp(test3, "Hello empty   ", strlen(test3)) == 0);
	assert(strncmp(test4, "Hello 0 1 1 1", strlen(test4)) == 0);

}