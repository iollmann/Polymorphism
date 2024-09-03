//
//  main.c
//  Polymorphism
//
//  Created by Ian Ollmann on 9/3/24.
//

#include "Animals.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {

    // on stack
    Object o;  Object_Constructor( &o);
    Object * oP = NEW(Object);
    
    Object_Destroy(&o);
    DELETE(oP);
    
    Lion lion; Lion_Constructor(&lion);
    Lion * lionP = NEW(Lion);

    printf( "The lion says %s\n", Animal_GetCall( (Animal*) &lion));
    printf( "The lionP says %s\n", Animal_GetCall( (Animal*) lionP));

    Object_Destroy((Object*) &lion);
    DELETE((Object*) lionP);

    Sheep sheep; Sheep_Constructor(&sheep);
    Sheep * sheepP = NEW(Sheep);

    printf( "The sheep says %s\n", Animal_GetCall( (Animal*) &sheep));
    printf( "The sheepP says %s\n", Animal_GetCall( (Animal*) sheepP));

    Object_Destroy((Object*) &sheep);
    DELETE((Object*) sheepP);

    return 0;
}
