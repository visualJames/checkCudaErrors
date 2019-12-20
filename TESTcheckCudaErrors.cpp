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
#include <nvrtc.h>


void testNvrtcResultNeu() {
    nvrtcResult result = NVRTC_ERROR_INVALID_PROGRAM;
    char *r = (char *) nvrtcGetErrorString(result);
    //handle with nvtrtcGetErrorString
    printf("With nvrtcGetErrorString you can print out the following string:\n%s\n\n", r);

    printf("this is my new function, which returns a exception:\n");
    //handle with my function
    try {
        checkNvrtcResultError(result);
    } catch (nvrtcResultException &e) {
      switch(e.type){
        case NVRTC_ERROR_INVALID_PROGRAM:
                std::cout << "Correct Exception caught" << std::endl;
                std::cout << e.what() << std::endl;
                break;
        case (nvrtcResult) 1 :  // NVRTC_ERROR_OUT_OF_MEMORY
            std::cout << "Wrong Exception caught" << std::endl;
            std::cout << e.what() << std::endl;
            break;
        default:
          std::cout << "Not Correct Exception caught" << std::endl;
          std::cout << e.what() << std::endl;
          break;
      }
    } catch (nvidiaException& e) {
        std::cout << "almost correct Exception caught" << std::endl;
        std::cout << e.what() << std::endl;
    }catch (std::exception &e) {
            // Other errors
            std::cout << "anderer Error\n";
            std::cout << e.what() << std::endl;
        }
    }


void testCudaResultNeu() {
    printf("ha\n");
    CUresult result = CUDA_ERROR_DEINITIALIZED;
    printf("ha%i\n", (int) result);
    const char* name;
    cuGetErrorName(result, &name); //method to get the error name from NVIDIA
    const char* description;
    cuGetErrorString(result, &description); //method to get the error description from NVIDIA
    printf("With cuGetErrorName you can print out the following string:\n%s\n\n", name);
    printf("With cuGetErrorString you can print out the following string:\n%s\n\n", description);


    printf("this is my new function, which returns a exception:\n");
    //handle with my function
    try {
        checkCUresultError(result);
    } catch (CUresultException &e) {
      switch(e.type){
        case CUDA_ERROR_DEINITIALIZED:
                std::cout << "Correct Exception caught" << std::endl;
                std::cout << e.what() << std::endl;
                break;
        default:
          std::cout << "Not Correct Exception caught" << std::endl;
          std::cout << e.what() << std::endl;
          break;
        }
      }catch (nvidiaException &e) {
        std::cout << "almost correct Exception caught" << std::endl;
        std::cout << e.what() << std::endl;
    }catch (std::exception &e) {
        // Other errors
        std::cout << "anderer Error\n";
        std::cout << e.what() << std::endl;
    }
}



void printAllCUresultExceptions();



void ErrorPointerThrow() {
    int nBytes = 10;
    CUdeviceptr d_A;
    try {
      checkCUresultError(cuMemAlloc(&d_A, (unsigned int)nBytes));
  } catch(CUresultException& e) {
      switch(e.type){
        case (CUresult)1 : // CUDA_ERROR_INVALID_VALUE
          std::cout << "Wrong Exception caught" << std::endl;
          std::cout << e.what() << std::endl;
          break;
        case CUDA_ERROR_NOT_INITIALIZED:
          std::cout << "Correct Exception caught" << std::endl;
          std::cout << e.what() << std::endl;
          break;
        default:
          std::cout << "Not Correct Exception caught" << std::endl;
          std::cout << e.what() << std::endl;
          break;
      }
  } catch(std::exception& e) {
      // Other errors
      std::cout << "anderer Error\n";
      std::cout << e.what() << std::endl;
  }
}

void giveColumnsSizeCommandConsole(){
   printf("command_line_size=%u\n", Unterfunktionen_checkCudaErrors::askTerminalSize());
}

void testNvrtcResult(){
    nvrtcProgram* prog  =NULL;
    nvrtcResult result = nvrtcDestroyProgram(prog);
    char* r =(char*) nvrtcGetErrorString(result);
    //handle with nvtrtcGetErrorString
    printf("With nvrtcGetErrorString you can print out the following string:\n%s\n\n", r);

        printf("this is my new function, which returns a exception:\n");
    //handle with my function
  try {
      checkNvrtcResultError(nvrtcDestroyProgram(prog));
  } catch(nvrtcResultException& e) {
    switch (e.type) {
      case (nvrtcResult)1: // NVRTC_ERROR_OUT_OF_MEMORY
        std::cout << "Wrong Exception caught" << std::endl;
        std::cout << e.what() << std::endl;
        break;
      case NVRTC_ERROR_INVALID_PROGRAM:
        std::cout << "Correct Exception caught" << std::endl;
        std::cout << e.what() << std::endl;
        break;
      default:
          std::cout << "Not Correct Exception caught" << std::endl;
          std::cout << e.what() << std::endl;
          break;
    }
  } catch(std::exception& e) {
      // Other errors
      std::cout << "anderer Error\n";
      std::cout << e.what() << std::endl;
  }

}


void errorWithoutCatch(){
       // throw new CUresultException<(CUresult) 1>("hey");
//     int nBytes = 10;
    CUdeviceptr d_A;
    checkCUresultError(cuMemAlloc(&d_A, (unsigned int)10));
}

int main(void) {

//     ErrorPointerThrow();
//     giveColumnsSizeCommandConsole();
//     printAllCUresultExceptions();
//     testNvrtcResult();
    errorWithoutCatch();
    return 0;
}
