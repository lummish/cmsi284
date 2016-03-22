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


int main(int argc, char* argv[]) {
    
    char *chordCheck = argv[1];
    char *chord = argv[2];
    char notes[] = "ABCDEFG";
    int noteNum = 7;
    
    int i;
    int root;
    
    for ( i = 0; i < 7; i = i + 1) {
        if (notes[i] == chord[0]) {
            root = i;
            break;
        }
    }
    
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
    printf("%sdim7: %s %c %c %c#\n", chord, chord, notes[third], notes[fifth], notes[dimSev]);

    return 0;
    
}