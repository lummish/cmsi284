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

	if (sCount != 3) {
		printf("Improper number of formatting specifiers\n");
		return "";
	}

	int templateLength = strlen(template);
	int adjLength = strlen(adjective);
	int nounLength = strlen(noun);
	int verbLength = strlen(verb);

	char* outStr = malloc(sizeof(char) * (templateLength + 
				   adjLength + nounLength + verbLength + 1)); //1 for null char
	sprintf(outStr, template, adjective, noun, verb);

	return outStr;
}

int main() {
	char* test = madlib("The %s %s %s.", "big", "man", "fell");
	printf(test);
	return 0;
}