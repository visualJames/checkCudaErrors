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

/*
*Template class for CUresult Exceptions
*CUresult name is the name and class_type of the exception
*/
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

/*
*Template class for nvrtcResult Exceptions
*nvrtcResult name is the name and class_type of the exception
*/
template<nvrtcResult name = (nvrtcResult)0>
class nvrtcResultException : public std::exception {
    private:
    std::string error;
    public:
    nvrtcResultException(std::string error){
        this->error = error;
    }
    const char * what () const throw () {
      return error.c_str();
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
                Unterfunktionen_checkCudaErrors::whichNvrtcResultError(error).c_str();
                exception = exception + "\n->occoured in file <" + file 
                +" in line " + std::to_string(line) + "\n";
      //choose which error to throw
        switch (error)
      {
      case 0:
        printf("no error caught in line %i in file %s\n",line, file);
        break;
      case 1: //NVRTC_ERROR_OUT_OF_MEMORY
        throw nvrtcResultException<NVRTC_ERROR_OUT_OF_MEMORY>(exception);
        break;
      case 2: //NVRTC_ERROR_PROGRAM_CREATION_FAILURE
        throw nvrtcResultException<NVRTC_ERROR_PROGRAM_CREATION_FAILURE>(exception);
        break;
      case 3: //NVRTC_ERROR_INVALID_INPUT
        throw nvrtcResultException<NVRTC_ERROR_INVALID_INPUT>(exception);
        break;
      case 4: //NVRTC_ERROR_INVALID_PROGRAM
        throw nvrtcResultException<NVRTC_ERROR_INVALID_PROGRAM>(exception);
        break;
      case 5: //NVRTC_ERROR_INVALID_OPTION
        throw nvrtcResultException<NVRTC_ERROR_INVALID_OPTION>(exception);
        break;
      case 6: //NVRTC_ERROR_COMPILATION
        throw nvrtcResultException<NVRTC_ERROR_COMPILATION>(exception);
        break;
      case 7: //NVRTC_ERROR_BUILTIN_OPERATION_FAILURE
        throw nvrtcResultException<NVRTC_ERROR_BUILTIN_OPERATION_FAILURE>(exception);
        break;
      case 8: //NVRTC_ERROR_NO_NAME_EXPRESSIONS_AFTER_COMPILATION
        throw nvrtcResultException<NVRTC_ERROR_NO_NAME_EXPRESSIONS_AFTER_COMPILATION>(exception);
        break;
      case 9: //NVRTC_ERROR_NO_LOWERED_NAMES_BEFORE_COMPILATION
        throw nvrtcResultException<NVRTC_ERROR_NO_LOWERED_NAMES_BEFORE_COMPILATION>(exception);
        break;
      case 10: //NVRTC_ERROR_NAME_EXPRESSION_NOT_VALID
        throw nvrtcResultException<NVRTC_ERROR_NAME_EXPRESSION_NOT_VALID>(exception);
        break;
      case 11: //NVRTC_ERROR_INTERNAL_ERROR
        throw nvrtcResultException<NVRTC_ERROR_INTERNAL_ERROR>(exception);
        break;
      default:
          printf("CUresult Error is unknown\n");
          exit(-1);      
          break;
          
    }
  }
 }


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
                +" in line " + std::to_string(line) + "\n";
      //choose which error to throw
        switch (error)
      {
        case 0:
          printf("no error caught in line %i in file %s\n",line, file);
          break;
        case 1:
                  throw CUresultException<(CUresult)1>(exception);
                  break;
        case 2:
                  throw CUresultException<(CUresult)2>(exception);
                  break;
        case 3:
                  throw CUresultException<(CUresult)3>(exception);
                  break;
        case 4:
                  throw CUresultException<(CUresult)4>(exception);
                  break;
        case 5:
                  throw CUresultException<(CUresult)5>(exception);
                  break;
        case 6:
                  throw CUresultException<(CUresult)6>(exception);
                  break;
        case 7:
                  throw CUresultException<(CUresult)7>(exception);
                  break;
        case 8:
                  throw CUresultException<(CUresult)8>(exception);
                  break;
        case 100:
                  throw CUresultException<(CUresult)100>(exception);
                  break;
        case 101:
                  throw CUresultException<(CUresult)101>(exception);
                  break;
        case 200:
                  throw CUresultException<(CUresult)200>(exception);
                  break;
        case 201:
                  throw CUresultException<(CUresult)201>(exception);
                  break;
        case 202:
                  throw CUresultException<(CUresult)202>(exception);
                  break;
        case 205:
                  throw CUresultException<(CUresult)205>(exception);
                  break;
        case 206:
                  throw CUresultException<(CUresult)206>(exception);
                  break;
        case 207:
                  throw CUresultException<(CUresult)207>(exception);
                  break;
        case 208:
                  throw CUresultException<(CUresult)208>(exception);
                  break;
        case 209:
                  throw CUresultException<(CUresult)209>(exception);
                  break;
        case 210:
                  throw CUresultException<(CUresult)210>(exception);
                  break;
        case 211:
                  throw CUresultException<(CUresult)211>(exception);
                  break;
        case 212:
                  throw CUresultException<(CUresult)212>(exception);
                  break;
        case 213:
                  throw CUresultException<(CUresult)213>(exception);
                  break;
        case 214:
                  throw CUresultException<(CUresult)214>(exception);
                  break;
        case 215:
                  throw CUresultException<(CUresult)215>(exception);
                  break;
        case 216:
                  throw CUresultException<(CUresult)216>(exception);
                  break;
        case 217:
                  throw CUresultException<(CUresult)217>(exception);
                  break;
        case 218:
                  throw CUresultException<(CUresult)218>(exception);
                  break;
        case 219:
                  throw CUresultException<(CUresult)219>(exception);
                  break;
        case 220:
                  throw CUresultException<(CUresult)220>(exception);
                  break;
        case 221:
                  throw CUresultException<(CUresult)221>(exception);
                  break;
        case 300:
                  throw CUresultException<(CUresult)300>(exception);
                  break;
        case 301:
                  throw CUresultException<(CUresult)301>(exception);
                  break;
        case 302:
                  throw CUresultException<(CUresult)302>(exception);
                  break;
        case 303:
                  throw CUresultException<(CUresult)303>(exception);
                  break;
        case 304:
                  throw CUresultException<(CUresult)304>(exception);
                  break;
        case 400:
                  throw CUresultException<(CUresult)400>(exception);
                  break;
        // case 401:
        //           throw CUresultException<(CUresult)401>(exception);
        //           break;
        case 500:
                  throw CUresultException<(CUresult)500>(exception);
                  break;
        case 600:
                  throw CUresultException<(CUresult)600>(exception);
                  break;
        case 700:
                  throw CUresultException<(CUresult)700>(exception);
                  break;
        case 701:
                  throw CUresultException<(CUresult)701>(exception);
                  break;
        case 702:
                  throw CUresultException<(CUresult)702>(exception);
                  break;
        case 703:
                  throw CUresultException<(CUresult)703>(exception);
                  break;
        case 704:
                  throw CUresultException<(CUresult)704>(exception);
                  break;
        case 705:
                  throw CUresultException<(CUresult)705>(exception);
                  break;
        case 708:
                  throw CUresultException<(CUresult)708>(exception);
                  break;
        case 709:
                  throw CUresultException<(CUresult)709>(exception);
                  break;
        case 710:
                  throw CUresultException<(CUresult)710>(exception);
                  break;
        case 711:
                  throw CUresultException<(CUresult)711>(exception);
                  break;
        case 712:
                  throw CUresultException<(CUresult)712>(exception);
                  break;
        case 713:
                  throw CUresultException<(CUresult)713>(exception);
                  break;
        case 714:
                  throw CUresultException<(CUresult)714>(exception);
                  break;
        case 715:
                  throw CUresultException<(CUresult)715>(exception);
                  break;
        case 716:
                  throw CUresultException<(CUresult)716>(exception);
                  break;
        case 717:
                  throw CUresultException<(CUresult)717>(exception);
                  break;
        case 718:
                  throw CUresultException<(CUresult)718>(exception);
                  break;
        case 719:
                  throw CUresultException<(CUresult)719>(exception);
                  break;
        case 720:
                  throw CUresultException<(CUresult)720>(exception);
                  break;
        case 800:
                  throw CUresultException<(CUresult)800>(exception);
                  break;
        case 801:
                  throw CUresultException<(CUresult)801>(exception);
                  break;
      /*
    * 401, 802-804, 901-908 werden vom agamemnon Rechner nicht 
    * erkannt
    */
        // case 802:
        //           throw CUresultException<(CUresult)802>(exception);
        //           break;
        // case 803:
        //           throw CUresultException<(CUresult)803>(exception);
        //           break;
        // case 804:
        //           throw CUresultException<(CUresult)804>(exception);
        //           break;
        // case 900:
        //           throw CUresultException<(CUresult)900>(exception);
        //           break;
        // case 901:
        //           throw CUresultException<(CUresult)901>(exception);
        //           break;
        // case 902:
        //           throw CUresultException<(CUresult)902>(exception);
        //           break;
        // case 903:
        //           throw CUresultException<(CUresult)903>(exception);
        //           break;
        // case 904:
        //           throw CUresultException<(CUresult)904>(exception);
        //           break;
        // case 905:
        //           throw CUresultException<(CUresult)905>(exception);
        //           break;
        // case 906:
        //           throw CUresultException<(CUresult)906>(exception);
        //           break;
        // case 907:
        //           throw CUresultException<(CUresult)907>(exception);
        //           break;
        // case 908:
        //           throw CUresultException<(CUresult)908>(exception);
        //           break;
        case 999:
                  throw CUresultException<(CUresult)999>(exception);
                  break;
      default:
          printf("CUresult Error is unknown\n");
          exit(-1);      
          break;
      }
          
    }
}



#endif