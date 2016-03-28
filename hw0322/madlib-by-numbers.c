//madlib-by-numbers.
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isDigit(char c) {
	return (c >= '0' && c <= '9');
}

int char_as_int(char c) {
	return c - '0';
}
int string_space(char* template, int wordLens[]) { //may not want to remove pointer for wordlens
	int total_size = strlen(template);
	int original_size = total_size;

	int i;
	for (i = 0; i < original_size; i++) {
		if (isDigit(template[i])) {
			total_size += wordLens[char_as_int(template[i])] - 1; //-1 because we're removing number char
		}
	}

	return sizeof(char) * (total_size + 1); // +1 for null character
}

int append_word(char* dest, char* word, int idx) { //TODO: handle edge cases
	int i;
	int wordLen = strlen(word);
	for (i = 0; i < wordLen; i++) {
		dest[idx++] = word[i];
	}
	return idx; //to keep track of location in string;
}

char* madlib_by_numbers(char* template, int word_count, char* words[]) {
	int wordLens[word_count];
	int i;
	
	for (i = 0; i < word_count; i++) {
		wordLens[i] = strlen(words[i]);
	}


	char* result  = (char*) malloc(string_space(template, wordLens)); 
	int templateLen = strlen(template);

	int resultIdx = 0;
	for (i = 0; i < templateLen; i++) {
		if (isDigit(template[i])) {
			if (char_as_int(template[i]) >= 0 && char_as_int(template[i]) < word_count) {
				resultIdx = append_word(result, words[char_as_int(template[i])], resultIdx); //now we're here!
			} else {
				result[resultIdx++] = template[i]; 
			}
		} else {
			result[resultIdx++] = template[i]; 
		}
	}

	result[resultIdx] = '\0';

	return result;
}

int main(){
	char* wds[] = {"brilliant", "git", "swim"};

	char* madlib = madlib_by_numbers("Hello there you 0 1 9, would you like to go 2ing?", 3, wds);
	printf("%s\n", madlib);
	free(madlib);
	return 0;
}



	