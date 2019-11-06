# checkCudaErrors
# check CUresult
CUDA Error Checking Functions: 
English:
Description: A header for checking errors in CUDA Driver Api.
             The function checkCudaErrors checks the result of CUresult
             and returns it value. 
Source:      All names and descriptions are from the NVIDIA CUDA TYPES Documentation:
https://docs.nvidia.com/cuda/cuda-driver-api/group__CUDA__TYPES.html#group__CUDA__TYPES_1gc6c391505e117393cc2558fff6bfc2e9 

Deutsch:
In diesem Repository wird ein Tool geliefert, womit man CUresult Fehler abfangen kann. Diese Methode liefert dann die Zeile, wo der Fehler aufgetreten ist, und die Art des Fehlers zurück.
Es wurde hierfür sich auf die NVIDIA Dokumentation 
https://docs.nvidia.com/cuda/cuda-driver-api/group__CUDA__TYPES.html#group__CUDA__TYPES_1gc6c391505e117393cc2558fff6bfc2e9 
bezogen.
Es ist verwendbar wie bei TESTcheckCudaErrors zu sehen.
