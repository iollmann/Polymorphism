//
//  Animals.h
//  Polymorphism
//
//  Created by Ian Ollmann on 9/3/24.
//

#ifndef Animals_h
#define Animals_h

#include "Polymorphism.h"

// class Animal : public Object
// {
// public:
//     Animal() : Object(){}
//
//     virtual const char * GetCall() = 0;
// }

typedef struct Animal Animal;
typedef struct Animal_Vtbl
{
    Vtbl        object;
    const char * __nonnull (*__nonnull getCall)(const Animal * __nonnull me);
}Animal_Vtbl;

const Animal_Vtbl kAnimalVtbl = (Animal_Vtbl)
{
    .object = (Vtbl){
        .name = "Animal",
        .parent = &kObjectVtbl,
        .dtor = NULL
    },
    .getCall = NULL     // pure virtual
};

typedef struct Animal
{
    Object      object;
}Animal;

static inline void Animal_Constructor( Animal * __nonnull me)
{
    Object_Constructor(&me->object);
    me->object.vtbl = &kAnimalVtbl.object;
}
static inline const Animal_Vtbl * __nonnull Animal_GetClass(const Animal * __nonnull me){ return (const Animal_Vtbl*) me->object.vtbl; }
static inline const char * __nonnull Animal_GetCall(const Animal * __nonnull me){ return Animal_GetClass(me)->getCall(me);}

// class Lion : public Animal
// {
// public:
//     Lion() : Animal(){}
//
//     virtual const char * GetCall() const { return "Roar!"; }
// }

typedef struct Lion_Vtbl
{
    Animal_Vtbl        animal;
}Lion_Vtbl;

typedef struct Lion
{
    Animal  animal;
}Lion;

static inline const char * __nonnull Lion_GetCall(const Animal * __nonnull me){ return "Roar!"; }

const Lion_Vtbl kLionVtbl = (Lion_Vtbl)
{
    .animal = (Animal_Vtbl)
    {
        .object = (Vtbl){
            .name = "Lion",
            .parent = &kAnimalVtbl.object,
            .dtor = NULL
        },
        .getCall = Lion_GetCall
    }
};

static inline void Lion_Constructor( Lion * __nonnull me)
{
    Animal_Constructor( &me->animal);
    me->animal.object.vtbl = &kLionVtbl.animal.object;
}



// class Sheep : public Animal
// {
// public:
//     Sheep() : Animal(){}
//
//     virtual const char * GetCall() const { return "Baaa!"; }
// }

typedef struct Sheep_Vtbl
{
    Animal_Vtbl        animal;
}Sheep_Vtbl;

typedef struct Sheep
{
    Animal  animal;
}Sheep;

static inline const char * __nonnull Sheep_GetCall(const Animal * __nonnull me){ return "Baa!"; }

const Sheep_Vtbl kSheepVtbl = (Sheep_Vtbl)
{
    .animal = (Animal_Vtbl)
    {
        .object = (Vtbl){
            .name = "Sheep",
            .parent = &kAnimalVtbl.object,
            .dtor = NULL
        },
        .getCall = Sheep_GetCall
    }
};

static inline void Sheep_Constructor( Sheep * __nonnull me)
{
    Animal_Constructor( &me->animal);
    me->animal.object.vtbl = &kSheepVtbl.animal.object;
}


#endif /* Animals_h */
