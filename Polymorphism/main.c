//
//  main.c
//  Polymorphism
//
//  Created by Ian Ollmann on 9/3/24.
//

#include "Animals.h"
#include <stdio.h>

int main(int argc, const char * argv[]) {

    // Base class
    Object o;  Object_Constructor( &o);     // on stack
    Object * oP = NEW(Object);              // on heap
    
    // clean up
    Object_Destroy(&o);
    DELETE(oP);
    
    // Make some lion objects
    Lion lion; Lion_Constructor(&lion);
    Lion * lionP = NEW(Lion);

    // Use them polymorphically
    printf( "The lion says %s\n", Animal_GetCall( (Animal*) &lion));
    printf( "The lionP says %s\n", Animal_GetCall( (Animal*) lionP));

    // clean up lions
    Object_Destroy((Object*) &lion);
    DELETE((Object*) lionP);

    // Do the same for sheep
    Sheep sheep; Sheep_Constructor(&sheep);
    Sheep * sheepP = NEW(Sheep);

    printf( "The sheep says %s\n", Animal_GetCall( (Animal*) &sheep));
    printf( "The sheepP says %s\n", Animal_GetCall( (Animal*) sheepP));

    Object_Destroy((Object*) &sheep);
    DELETE((Object*) sheepP);

    return 0;
}
