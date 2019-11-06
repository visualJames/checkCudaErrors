// Copyright 2019 André Hodapp
#include <stdio.h>
#include <stdlib.h>


#include <cuda.h>
#include <builtin_types.h>  // z.B. für dim3

// C++ Headers
#include <string>
#include <vector>
#include <iostream>

#include "checkCudaErrors.hpp"


void ErrorPointer() {
    int nBytes = 10;
    CUdeviceptr d_A;
    checkCudaErrors(cuMemAlloc(&d_A, (unsigned int)nBytes));
    printf("Dieser Pointer %llu kann nicht ausgegeben", d_A);
    printf(" werden da vorher abbricht wegen fehlendem Device\n");
}

void ErrorPointerThrow() {
    int nBytes = 10;
    CUdeviceptr d_A;
    try {
      checkCudaError(cuMemAlloc(&d_A, (unsigned int)nBytes));
   } catch(CUresultException& e) {
      std::cout << "MyException caught" << std::endl;
      std::cout << e.what() << std::endl;
   } catch(std::exception& e) {
      //Other errors
      std::cout << "anderer Error\n";
      std::cout << e.what() << std::endl;
   }
}


int main(void) {
    CUresult res = (CUresult) 1;
    printf("%s\n", Unterfunktionen_checkCudaErrors::welcherError(res).c_str());
    ErrorPointerThrow();
    return 0;
}
