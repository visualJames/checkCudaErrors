C++FLAGS := -Wall -Wextra -pedantic -Werror -std=c++14 -fPIC
TESTcheckCudaErrors: TESTcheckCudaErrors.cpp checkCudaErrors.o 
	g++ $(C++FLAGS) -o TESTcheckCudaErrors TESTcheckCudaErrors.cpp checkCudaErrors.o -lcuda

checkCudaErrors.o: checkCudaErrors.cpp
	g++ $(C++FLAGS) -c checkCudaErrors.cpp 

clean:
	rm *.o TESTcheckCudaErrors

run:
	./TESTcheckCudaErrors


