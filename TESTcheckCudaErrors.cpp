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

void printAllCUresultExceptions();



void ErrorPointerThrow() {
    int nBytes = 10;
    CUdeviceptr d_A;
    try {
      checkCUresultError(cuMemAlloc(&d_A, (unsigned int)nBytes));
  } catch(CUresultException<(CUresult)1>& e) {  // CUDA_ERROR_INVALID_VALUE
      std::cout << "Wrong Exception caught" << std::endl;
      std::cout << e.what() << std::endl;
  } catch(CUresultException<CUDA_ERROR_NOT_INITIALIZED>& e) {
      std::cout << "Correct Exception caught" << std::endl;
      std::cout << e.what() << std::endl;
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
  } catch(nvrtcResultException<(nvrtcResult)1>& e) {  // NVRTC_ERROR_OUT_OF_MEMORY
      std::cout << "Wrong Exception caught" << std::endl;
      std::cout << e.what() << std::endl;
  } catch(nvrtcResultException<NVRTC_ERROR_INVALID_PROGRAM>& e) {
      std::cout << "Correct Exception caught" << std::endl;
      std::cout << e.what() << std::endl;
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


void printAllCUresultExceptions(){
   printf("______ALL_EXCEPTIONS______\n");
   const char *file = __FILE__;
   const int line = __LINE__;
   std::string exception = 
                Unterfunktionen_checkCudaErrors::whichError((CUresult)1).c_str();
                exception = exception + "\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)1>(exception).what());       

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)2).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)2>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)3).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)3>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)4).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)4>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)5).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)5>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)6).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)6>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)7).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)7>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)8).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)8>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)100).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)100>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)101).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)101>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)200).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)200>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)201).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)201>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)202).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)202>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)205).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)205>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)206).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)206>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)207).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)207>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)208).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)208>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)209).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)209>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)210).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)210>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)211).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)211>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)212).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)212>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)213).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)213>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)214).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)214>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)215).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)215>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)216).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)216>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)217).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)217>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)218).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)218>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)219).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)219>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)220).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)220>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)221).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)221>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)300).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)300>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)301).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)301>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)302).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)302>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)303).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)303>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)304).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)304>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)400).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)400>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)401).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)401>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)500).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)500>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)600).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)600>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)700).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)700>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)701).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)701>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)702).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)702>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)703).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)703>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)704).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)704>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)705).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)705>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)708).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)708>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)709).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)709>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)710).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)710>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)711).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)711>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)712).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)712>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)713).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)713>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)714).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)714>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)715).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)715>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)716).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)716>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)717).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)717>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)718).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)718>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)719).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)719>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)720).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)720>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)800).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)800>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)801).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)801>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)802).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)802>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)803).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)803>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)804).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)804>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)900).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)900>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)901).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)901>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)902).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)902>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)903).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)903>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)904).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)904>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)905).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)905>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)906).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)906>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)907).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)907>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)908).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)908>(exception).what());
          

           exception = Unterfunktionen_checkCudaErrors::whichError((CUresult)999).c_str();
        exception = exception+"\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
   printf("%s\n",CUresultException<(CUresult)999>(exception).what());

       printf("______END_ALL_EXCEPTIONS______\n");   
}