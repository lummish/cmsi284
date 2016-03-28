//
//  chord.c
//  
//
//  Created by Harris Lummis on 3/21/16.
//
//

#include "chord.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main(int argc, char* argv[]) {
    char *chord = argv[1];
    int chordLen = strlen(chord);
    char* notes[] = {"A", "A#", "B", "C", "C#", "D", "D#", 
                     "E", "F", "F#", "G", "G#"};
    int noteNum = 12;
    
    int i;
    int root = -1;
    
    for ( i = 0; i < noteNum; i = i + 1) {
        if (strlen(notes[i]) == chordLen && strncmp(notes[i], chord, chordLen) == 0) { //why seg fault if # is first character?
            root = i;
            break;
        }
    }

    assert(root >= 0); //if root is not a valid note, error
    
    int maj_third = (root + 4) % noteNum;
    int min_third = (root + 3) % noteNum;
    int perf_fifth = (root + 7) % noteNum;
    int min_seventh = (root + 10) % noteNum;
    int maj_sixth = (root + 9) % noteNum;
   
    //major
    printf("%s: %s %s %s\n", chord, chord, notes[maj_third], notes[perf_fifth]);
    //minor
    printf("%sm: %s %s %s\n", chord, chord, notes[min_third], notes[perf_fifth]);
    //major 7th
    printf("%s7: %s %s %s %s\n", chord, chord, notes[maj_third], notes[perf_fifth], 
           notes[min_seventh]);
    //dim 7th
    printf("%sdim7: %s %s %s %s\n", chord, chord, notes[maj_third], notes[perf_fifth], 
           notes[maj_sixth]);

    return 0;
    
}