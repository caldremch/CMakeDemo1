#include <iostream>
#include "config.h"

#ifdef  USER_MYMATH
#include "calculate/MyMath.h"
#else

#endif

int main() {
#ifdef  USER_MYMATH
    std::cout << "Hello, World!" << add(1,3)<< std::endl;
#else
    std::cout << "Hello, World! without myMath" << std::endl;
#endif

    return 0;
}