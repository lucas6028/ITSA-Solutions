#include <iostream>
using namespace std;

// Base case for variadic template function to end recursion
void dbg() { cerr << '\n'; }

// Variadic template function for printing multiple arguments
template<class T, class ...U> 
void dbg(T a, U ...b) { 
    cerr << a << ' '; 
    dbg(b...); 
}

// Template function for printing range [l, r) iterators
template<class T> 
void org(T l, T r) { 
    while (l != r) 
        cerr << *l++ << ' '; 
    cerr << '\n'; 
}

// Macro to print debug information with argument names and values
#define debug(args...) (dbg("#> (" + string(#args) + ") = (", args, ")"))

// Macro to print range debug information
#define orange(args...) (cerr << "#> [" + string(#args) + ") = ", org(args))

