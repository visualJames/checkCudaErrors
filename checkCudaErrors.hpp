// Copyright 2019 André Hodapp
#ifndef HEADER_checkCudaErrors
	#define HEADER_checkCudaErrors
#include <stdio.h>
#include <stdlib.h>


#include <cuda.h>
#include <builtin_types.h>  // z.B. für dim3

// C++ Headers
#include <string>
#include <vector>


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
std::string welcherError(CUresult& error);


// This will output the proper CUDA error strings
// in the event that a CUDA host call returns an error
#define checkCudaErrors(error)  __checkCudaErrors (error, __FILE__, __LINE__);
inline void __checkCudaErrors(CUresult error,
 const char *file, const int line ) {
    if( CUDA_SUCCESS != error) {
        fprintf(stderr,
                "%s \n->error occoured in file <%s> in line %i.\n",
               welcherError(error).c_str(),
                file, line );
        exit(-1);
    }
}



#endif