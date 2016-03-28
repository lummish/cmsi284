//interval.c

#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if (argc != 3) {
		printf("Sorry, you entered an incorrect number of arguments\n");
		return 0;
	}

	char* notes[] = {"A", "A#", "B", "C", "C#", "D", "D#", 
					 "E", "F", "F#", "G", "G#"};
	char* interval_names[] = {"perfect octave", "minor second", "major second",
							  "minor third", "major third", "perfect fourth",
							  "tritone", "perfect fifth", "minor sixth",
							  "major sixth", "minor seventh", "major seventh"};
	int numNotes = 12;
	//test if arguments are valid! Must make sure if its 
	//char* startNote = argv[1]; //may need to change to 2
	//char* endNote = argv[2];

	int startNoteIdx = -1;
	int endNoteIdx = -1;
	int i;

	for (i = 0; i < numNotes; i++) {
		
		if ((strlen(notes[i]) == strlen(argv[1])) && 
			strncmp(notes[i], argv[1], strlen(argv[1])) == 0) {
			startNoteIdx = i;
		}
		if ((strlen(notes[i]) == strlen(argv[2])) &&
			(strncmp(notes[i], argv[2], strlen(argv[2])) == 0)) {
			endNoteIdx = i;
		}
	}

	if (startNoteIdx < 0 || endNoteIdx < 0) {
		printf("Sorry, one of your notes is invalid.\n");
		return 0;
	}

	int interval = 0;
	i = startNoteIdx;

	while (i % numNotes != endNoteIdx) {
		interval++;
		i++;
	}

	printf("%s to %s is a %s.\n", argv[1], argv[2], interval_names[interval]);

	return 0;
}