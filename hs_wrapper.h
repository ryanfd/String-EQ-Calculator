// Include Haskell FFI file, which we will use to initialize a Haskell runtime
#include "HsFFI.h"

/* #ifdef __GLASGOW_HASKELL__ */
#include "hsFuncs_stub.h"
/* #endif */

#include <stdio.h>
#include <stdlib.h>

int callFact(int i);

int callFib(int i);

int callHailstone(int i);