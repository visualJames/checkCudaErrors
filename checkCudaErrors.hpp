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
#include <exception>

namespace Unterfunktionen_checkCudaErrors {
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

}

// // This will output the proper CUDA error strings
// // in the event that a CUDA host call returns an error
// #define checkCudaErrors(error)  __checkCudaErrors (error, __FILE__, __LINE__);
// inline void __checkCudaErrors(CUresult error,
//  const char *file, const int line ) {
//     if( CUDA_SUCCESS != error) {
//         fprintf(stderr,
//                 "%s \n->error occoured in file <%s> in line %i.\n",
//               Unterfunktionen_checkCudaErrors::welcherError(error).c_str(),
//                 file, line );
//         exit(-1);
//     }
// }
//________________________________________________________________
//CUresult Exceptions

template<CUresult name = (CUresult)0>
class CUresultException : public std::exception {
    private:
    std::string error;
    public:
    CUresultException(std::string error){
        this->error = error;
    }
    const char * what () const throw () {
      return error.c_str();
   }
};

// class CUresultException_CUDA_ERROR_NOT_INITIALIZED : public CUresultException {
//     public:
//     CUresultException_CUDA_ERROR_NOT_INITIALIZED(std::string error):CUresultException(error){}
// };


//________________________________________________________________

// This will throw as an error the proper CUDA error strings
// in the event that a CUDA host call returns an error
#define checkCUresultError(error)  __checkCUresultError (error, __FILE__, __LINE__);
inline void __checkCUresultError(const CUresult error,
 const char *file, const int line ) {
    if( CUDA_SUCCESS != error) {
       //create string for exception 
      std::string exception = 
                Unterfunktionen_checkCudaErrors::whichError(error).c_str();
                exception = exception + "\n->occoured in file <" + file 
                +"in line " + std::to_string(line) + "\n";
          printf("Error wird geworfen:\n");
      //choose which error to throw
        switch (error)
      {
        case 3:
          throw CUresultException<(CUresult)3>(exception);
          break;
      default:
          printf("CUresult Error is unknown\n");
          exit(-1);      
          break;
      }
          
    }
}


// // This will throw as an error the proper CUDA error strings
// // in the event that a CUDA host call returns an error
// #define checkCUresultError(error)  __checkCUresultError (error, __FILE__, __LINE__);
// inline void __checkCUresultError(CUresult error,
//  const char *file, const int line ) {
//     if( CUDA_SUCCESS != error) {
//        //create string for exception 
//       std::string exception = 
//                 Unterfunktionen_checkCudaErrors::welcherError(error).c_str();
//                 exception = exception + "\n->occoured in file <" + file 
//                 +"in line " + std::to_string(line) + "\n";
//           printf("Error wird geworfen:\n");
//       //choose which error to throw
//       switch (error)
//       {
//         case 0:
//           throw CUresultException_CUDA_ERROR_NOT_INITIALIZED(exception);
//           break;
//       default:
//           printf("CUresult Error is unknown\n");      
//           break;
//       }
//     }
// }



// // This will throw as an error the proper CUDA error strings
// // in the event that a CUDA host call returns an error
// #define checkCudaError(error)  __checkCudaError (error, __FILE__, __LINE__);
// inline void __checkCudaError(CUresult error,
//  const char *file, const int line ) {
//     if( CUDA_SUCCESS != error) {
//             std::string exception = 
//               Unterfunktionen_checkCudaErrors::welcherError(error).c_str();
//               exception = exception + "\n->occoured in file <" + file 
//               +"in line " + std::to_string(line) + "\n";
//         printf("Error wird geworfen:\n");
//         throw CUresultException(exception);
//     }
// }



#endif