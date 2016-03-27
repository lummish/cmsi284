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
    
    char *chordCheck = argv[1];
    char *chord = argv[2];
    char notes[] = "ABCDEFG";
    int noteNum = 7;
    
    int i;
    int root = -1;
    
    for ( i = 0; i < 7; i = i + 1) {
        if (notes[i] == chord[0]) { //why seg fault if # is first character?
            root = i;
            break;
        }
    }

    assert(root >= 0); //if root is not a valid note, error
    
    int third = (root + 2) % 7;
    int fifth = (root + 4) % 7;
    int seventh = (root + 6) % 7;
    int dimSev = (root + 5) % 7;
   
    //major
    printf("%s: %s %c# %c#\n", chord, chord, notes[third], notes[fifth]);
    //minor
    printf("%sm: %s %c %c#\n", chord, chord, notes[third], notes[fifth]);
    //major 7th
    printf("%s7: %s %c# %c# %c\n", chord, chord, notes[third], notes[fifth], notes[seventh]);
    //dim 7th
    printf("%sdim7: %s %c %c %c#\n", chord, chord, notes[third], notes[fifth], notes[dimSev]);

    return 0;
    
}