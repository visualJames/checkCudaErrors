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



void ErrorPointerThrow() {
    int nBytes = 10;
    CUdeviceptr d_A;
    try {
      checkCUresultError(cuMemAlloc(&d_A, (unsigned int)nBytes));
   } catch(CUresultException<(CUresult)1>& e) {
      std::cout << "Wrong Exception caught" << std::endl;
      std::cout << e.what() << std::endl;
   } catch(CUresultException<(CUresult)3>& e) {
      std::cout << "Correct Exception caught" << std::endl;
      std::cout << e.what() << std::endl;
   } catch(std::exception& e) {
      //Other errors
      std::cout << "anderer Error\n";
      std::cout << e.what() << std::endl;
   }
}

void giveColumnsSizeCommandConsole(){
   printf("command_line_size=%u\n", Unterfunktionen_checkCudaErrors::askTerminalSize());
}


int main(void) {
    ErrorPointerThrow();
    giveColumnsSizeCommandConsole();
    return 0;
}
