//
//  main.c
//  Polymorphism
//
//  Created by Ian Ollmann on 9/3/24.
//

#include "Animals.h"
#include <stdio.h>

void PrintAnimalCall( const Animal * animal, const char * type)
{
    printf( "The %s %s says \"%s\"\n",
            type,
            Object_GetClassName( (const Object*) animal),
            Animal_GetCall( animal ));
}

int main(int argc, const char * argv[]) {

    // Base class
    Object o = Object_Constructor();     // on stack
    Object * oP = NEW(Object);              // on heap
    
    // clean up
    Object_Destroy(&o);
    DELETE(oP);
    
    // Make some lion objects
    Lion lion = Lion_Constructor();
    Lion * lionP = NEW(Lion);

    // Use them polymorphically
    PrintAnimalCall( (const Animal*) &lion, "stack");
    PrintAnimalCall( (const Animal*) lionP, "heap");

    // clean up lions
    Object_Destroy((Object*) &lion);
    DELETE((Object*) lionP);

    // Do the same for sheep
    Sheep sheep = Sheep_Constructor();
    Sheep * sheepP = NEW(Sheep);

    PrintAnimalCall( (const Animal*) &sheep, "stack");
    PrintAnimalCall( (const Animal*) sheepP, "heap");

    Object_Destroy((Object*) &sheep);
    DELETE((Object*) sheepP);

    return 0;
}
