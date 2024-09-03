//
//  Polymorphism.h
//  Polymorphism
//
//  Created by Ian Ollmann on 9/3/24.
//

#ifndef Polymorphism_h
#define Polymorphism_h

// Include any headers we might need
#include <stdlib.h>         /// malloc / free
#include <string.h>         /// memset

// Make sure if any C++ files see this header, the don't get confused about the linkage
// This is C and we are using a flat namespace here
#ifdef __cplusplus
extern "C" {
#endif


// Forward declaration of type Object
typedef struct Object Object;

// Declare Vtbl so we don't have to write struct Vtbl everywhere in the definition for Vtbl
typedef struct Vtbl Vtbl;

/*! @abstract the base class for the VTBL type. This implements any virtual methods in the class hierarchy with function pointers*/
typedef struct Vtbl
{
    const char * __nonnull      name;       /// name of the class
    const Vtbl * __nullable     parent;     /// The parent class Vtbl.  NULL if root object
    
    /*! @abstract the virtual destructor function pointer, if any */
    void (* __nullable dtor)( Object * __nonnull a);
}Vtbl;

/*! @abstract The Vtbl for the Object root class */
static const Vtbl kObjectVtbl =(Vtbl)
{
    .name = "Object",
    .parent = NULL,
    .dtor = NULL
};


/*! @abstract The base class for polymorphic objects
 *  @discussions Child classes with virtual methods should
 *              1. Add a entry (e.g. ret (*virtual_method)(args)) to its Vtbl subclass
 *              2. define a static inline function that calls vtbl->virtual_method (args)*/
typedef struct Object
{
    const Vtbl * __nonnull vtbl;
}Object;

/*! @abstract return the class  for the object */
static inline const Vtbl * __nonnull Object_GetClass(const Object * __nonnull me){ return me->vtbl; }

/*! @abstract set the class name for the object. Needed in constructors. Otherwise dangerous.  */
static inline void Object_SetClass(Object * __nonnull me, const Vtbl * __nonnull vtbl){ me->vtbl = vtbl;}

/*! @abstract return the class name for the object */
static inline const char * __nonnull Object_GetClassName(const Object * __nonnull me){ return Object_GetClass(me)->name; }

/*! @abstract Constructor for Object base class .
 *  @discussion  Child classes should:
 *               1) call their parent constructor with {me, ...} as arguments
 *               2) set me->vtbl = <ChildType_Vtbl>
 *               3) initialize...  */
static inline Object Object_Constructor(void){Object result; result.vtbl = &kObjectVtbl; return result;}

/*! @abstract Make a new object on the heap  */
#define NEW( _type, ...)                                    \
    ({                                                      \
        _type * result = (_type*) calloc(sizeof(_type), 1); \
        if(result)                                          \
            result[0] = _type ## _Constructor(__VA_ARGS__); \
        /* return */ result;                                \
    })

// Convention: methods of <ObjectName> start with the <ObjectName>_ prefix
static inline void Object_Destroy(Object * __nonnull o)
{
    const Vtbl * __nonnull vtbl = Object_GetClass(o);
    if( vtbl->dtor)
        vtbl->dtor(o);
    if( (o->vtbl = vtbl->parent) )
        Object_Destroy(o);
}

#define DELETE(_object) Object_Delete(_object)
static inline void Object_Delete(Object * __nullable o){ if(o){ Object_Destroy(o); free(o); } }



#ifdef __cplusplus
}  // extern "C"
#endif

#endif /* Polymorphism_h */
