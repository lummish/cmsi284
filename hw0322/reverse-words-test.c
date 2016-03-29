//reverse-words-test.c
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "reverse-words.h"
#include "reverse-range-in-place.h"

void reverse_words(char* string);

void test_reverse_words() {
	char og_string_1[] = "Reverse my insides!"; //normal
	char* rev_string_1 = "insides! my Reverse";

	char og_string_2[] = " Reverse my insides!"; //leading space
	char* rev_string_2 = "insides! my Reverse ";

	char og_string_3[] = "Reverse my insides! "; //trailing space
	char* rev_string_3 = " insides! my Reverse";

	char og_string_4[] = "Reverse my  insides!"; //multiple spaces between words
	char* rev_string_4 = "insides!  my Reverse";

	char og_string_5[] = ""; //empty string
	char* rev_string_5 = "";

	reverse_words(og_string_1);
	assert(strncmp(og_string_1, rev_string_1, strlen(og_string_1)) == 0);

	reverse_words(og_string_2);
	assert(strncmp(og_string_2, rev_string_2, strlen(og_string_2)) == 0);
	
	reverse_words(og_string_3);
	assert(strncmp(og_string_3, rev_string_3, strlen(og_string_3)) == 0);
	
	reverse_words(og_string_4);
	assert(strncmp(og_string_4, rev_string_4, strlen(og_string_4)) == 0);
	
	reverse_words(og_string_5);
	assert(strncmp(og_string_5, rev_string_5, strlen(og_string_5)) == 0);
}

int main(int argc, char const *argv[])
{
	test_reverse_words();
	return 0;
}