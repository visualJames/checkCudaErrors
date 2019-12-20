// Copyright 2019 André Hodapp
#ifndef HEADER_checkCudaErrors
	#define HEADER_checkCudaErrors
#include <stdio.h>
#include <stdlib.h>


#include <cuda.h>
#include <builtin_types.h>  // z.B. für dim3
#include <nvrtc.h>

// C++ Headers
#include <string>
#include <vector>
#include <exception>

namespace Unterfunktionen_checkCudaErrors {
/*
  * returns the number of columns of the terminal
  */
  unsigned int askTerminalSize();

/*
* split a string in C++
* source: http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html
*/
template <class Container>
void split(const std::string& str, Container& cont,
              char delim = ' ');

/*
* this function indents the lines of the descripton to make look nicer :)
*/
std::string descriptionFkt(const std::string& desc);

/*
* returns the type of error
* the different errors are in :
* https://docs.nvidia.com/cuda/cuda-driver-api/group__CUDA__TYPES.html#group__CUDA__TYPES_1gc6c391505e117393cc2558fff6bfc2e9
*/
std::string whichError(const CUresult& error);


/*
* returns the type of nvrtc error
* the different errors are in :
* https://docs.nvidia.com/cuda/nvrtc/index.html#group__error_1g31e41ef222c0ea75b4c48f715b3cd9f0
* and the program itself is in https://github.com/ptillet/isaac/blob/master/include/isaac/external/CUDA/nvrtc.h
*/
std::string whichNvrtcResultError(const nvrtcResult& error);

}

// Copyright 2019 André Hodapp
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


#include <cuda.h>
#include <builtin_types.h>  // z.B. für dim3
#include <nvrtc.h>

// C++ Headers
#include <string>
#include <vector>
#include <exception>


/*
* this is the class of which nvrtcResultException and cudaResultException erben
*/
class nvidiaException : public std::exception {
protected:
    std::string error;
public:
    const char * what () const throw () {
        return error.c_str();
    }
};


/*
*class for nvrtcResult Exceptions
*nvrtcResult type is the name and class_type of the exception
*/
class nvrtcResultException : public nvidiaException {
public:
    nvrtcResult type;
    nvrtcResultException(nvrtcResult type, std::string error){
        this->type = type;
        this->error = error;
        printf("nvrtcResultException %i with description: '%s' created\n", (int)type , this->error.c_str());
    }
};

/*
*Template class for nvrtcResult Exceptions
*nvrtcResult type is the name and class_type of the exception
*/

class CUresultException : public nvidiaException {
public:
    CUresult type;
    CUresultException(CUresult type, std::string error){
        this->type = type;
        this->error = error;
        printf("CUresultException %i with description: '%s' created\n", (int)type, this->error.c_str());
    }
};




// This will throw as an error the proper CUDA error strings
// in the event that a CUDA host call returns an error
#define checkNvrtcResultError(error)  __checkNvrtcResultError (error, __FILE__, __LINE__);
inline void __checkNvrtcResultError(const nvrtcResult error,
 const char *file, const int line ) {
    if( NVRTC_SUCCESS != error) {
       //create string for exception
      std::string exception =
              nvrtcGetErrorString(error); //method to get the error name from NVIDIA
                exception = exception + "\n->occoured in file <" + file
                +" in line " + std::to_string(line) + "\n\n";
      throw nvrtcResultException(error, exception);
  }
 }


// This will throw as an error the proper CUDA error strings
// in the event that a CUDA host call returns an error
#define checkCUresultError(error)  __checkCUresultError (error, __FILE__, __LINE__);
inline void __checkCUresultError(const CUresult error,
                                    const char *file, const int line ) {
    if( CUDA_SUCCESS != error) {
        //create string for exception
        const char* name;
        cuGetErrorName(error, &name); //method to get the error name from NVIDIA
        const char* description;
        cuGetErrorString(error, &description); //method to get the error description from NVIDIA
        std::string exception = name;
        exception = exception + "\n->occoured in file <" + file
                    +" in line " + std::to_string(line) + "\n" +
										"  ->kurz: "+ description + "\n"
										"  ->lang: \n"+ Unterfunktionen_checkCudaErrors::whichError(error).c_str()
										+"\n\n";
        //choose which error to throw
        throw CUresultException(error, exception);
    }
}


#endif
