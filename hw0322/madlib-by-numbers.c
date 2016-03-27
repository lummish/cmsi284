//madlib-by-numbers.
#include <string.h>
#include <stdlib.h>

int isDigit(char c) {
	return (c >= 0 && c <= 9);
}

char* spacey_empty_string(char* template, int wordLens[]) { //may not want to remove pointer for wordlens
	int total_size = strlen(template);
	int original_size = total_size;

	int i;
	for (i = 0; i < original_size; i++) {
		if (isDigit(template[i])) {
			total_size += wordLens[template[i]] - 1;
		}
	}

	return (char*) malloc(total_size + 1); // +1 for null character
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

	char* result  = spacey_empty_string(template, wordLens);
	int templateLen = strlen(template);

	int resultIdx = 0;
	for (i = 0; i < templateLen; i++) {
		if (isDigit(template[i])) {
			if (i >= 0 && i < word_count) {
				resultIdx = append_word(result, words[template[i]], resultIdx);
			} 
		} else {
			result[resultIdx++] = template[i];
		}
	}
	return result;
}




	