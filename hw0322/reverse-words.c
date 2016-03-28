#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "reverse-range-in-place.h"

/* A method which reverses the order of the words found in a string. White space, as well,
   is found in reverse order from the original string*/
void reverse_words(char* string) {
	int stringLen = strlen(string);

	//first reverse full string to get correct reverse word order
	reverse_range_in_place(string, 0, stringLen - 1);

	int i;
	int wordStartIdx;
	int wordEndIdx; //unnecessary
	bool isWord = false;

	for (i = 0; i < stringLen; i++) {
		if (string[i] != ' ') {
			if (!isWord) {
				wordStartIdx = i;
				isWord = true;
			} 
		} else {
			if (isWord) {
				reverse_range_in_place(string, wordStartIdx, i - 1);
				isWord = false;
			} 
		}
	}

	//if there are no trailing spaces, must reverse final word
	if (isWord) {
		reverse_range_in_place(string, wordStartIdx, stringLen - 1);
	}
}