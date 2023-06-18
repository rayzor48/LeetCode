#include <iostream>
#include "myAToI.h"

int main() {
    MyStd::Solution myAToI;

    auto result = myAToI.myAtoi("  -0012a42");

    std::cout << "result = " << result << std:: endl;

    return 0;
}
