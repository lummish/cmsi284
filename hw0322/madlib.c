//madlib.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* madlib(char* template, char* adjective, char* noun, char* verb){
	int i;
	int sCount = 0; //to ensure adequate format space

	for (int i = 0; template[i] != '\0'; i = i + 1) {
		if (template[i] == '%' && template[i + 1] == 's') {
			sCount = sCount + 1;
		}
	}

	assert(sCount == 3);

	int templateLength = strlen(template);
	int adjLength = strlen(adjective);
	int nounLength = strlen(noun);
	int verbLength = strlen(verb);

	char outStr[templateLength + adjLength + nounLength + verbLength + 1]; //1 for newline char
	strcpy(outStr, template);
	strcat(outStr, "\n");
	printf(outStr, adjective, noun, verb);

	return template;
}

int main() {
	madlib("The %s %s %s.", "big", "man", "fell");
	return 0;
}