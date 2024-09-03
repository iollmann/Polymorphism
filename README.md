# Polymorphism
An educational exercise implementing C++ polymorphism in C

My son is taking his first college programming class (at his actual college) which teaches programming
in C. He's been doing C++ for the last year. The look of distaste on his face was memorable. 
You can actually do quite a lot of C++ in C. It is just more work. Templates are definitely
out, but polymorphism is possible as this exercise shows. It may provide an insight into 
how C++ works. 

I actually had to do this once while working at Apple.  The PowerPC 64-bit architecture had
just been released in Jaguar (X.2). We were one of the few frameworks asked to go 64-bit 
on day 1. However, Apple hadn't managed to finish a C++ compiler for it then, so all of 
our C++ test infrastructure had to be rolled back to C. For all I know, it still has 
cruft like this in it.  Steve Jobs had a lot of trouble pronouncing Jaguar.

With publicly facing vtbls (virtual function tables) like this a lot more becomes possible
like having an object magically change class on the fly.  Whether or not this is a good 
idea is another matter. It is a little inconvenient to use. You can see the effort the 
C++ committee went through to clean that up, and why various bits work the way they do.
