//
//  madlib.c
//  hw0322
//
//  Created by Harris Lummis on 3/8/16.
//
//

#include <stdio.h>
#include <stdlib.h>

char* madlib(char* template, char* adjective, char* noun, char* verb){
    sprintf(template, adjective, noun, verb);
    return template;
}

int main (){
    madlib("This is a %s fucking %s that prints.", "cool", "fucking", "string");
    return 0;
}
