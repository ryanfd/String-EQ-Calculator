// Include Haskell FFI file, which we will use to initialize a Haskell runtime
#include "HsFFI.h"

/* #ifdef __GLASGOW_HASKELL__ */
#include "hsFuncs_stub.h"
/* #endif */

#include "hs_wrapper.h"

int callFact(int i)
{
    return fact_hs(i);
}

int callFib(int i)
{
    return fib_hs(i);
}

int callHailstone(int i)
{
    return hailstone_hs(i);
}

int main( int argc, char *argv[] )
{
  // Initialize Haskell Runtime _before_ any calls to the Haskell code
  hs_init (&argc, &argv);

//   int num = atoi(argv[1]);
  
  // Make a call to Haskell code
  printf("[Haskell] Factorial: %d\n", callFact(atoi(argv[1])));
  printf("[Haskell] Fibonacci: %d\n", callFib(atoi(argv[1])));
  printf("[Haskell] Hailstone: %d\n", callHailstone(atoi(argv[1])));
}