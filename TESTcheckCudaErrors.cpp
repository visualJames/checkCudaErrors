// Copyright 2019 André Hodapp
#include <stdio.h>
#include <stdlib.h>


#include <cuda.h>
#include <builtin_types.h>  // z.B. für dim3

// C++ Headers
#include <string>
#include <vector>

#include "checkCudaErrors.hpp"

void ErrorPointer() {
    int nBytes = 10;
    CUdeviceptr d_A,*d_B, d_C;  //cuMemAlloc(d_A) mit d_A als Pointer funktioniert nicht 
    d_B = NULL;
    checkCudaErrors(cuMemAlloc(&d_A, (unsigned int)nBytes));
    checkCudaErrors(cuMemAlloc(d_B, nBytes));
    checkCudaErrors(cuMemAlloc(&d_C, nBytes));
}


int main(void) {
    ErrorPointer();
    return 0;
}
