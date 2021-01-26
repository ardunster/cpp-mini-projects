#include <iostream>

#include "maths/addition.hpp"
#include "maths/division.hpp"
#include "print/print_result.hpp"

int main() {
    float first_no, second_no, result_add, result_div;

    std::cout << "Enter first number:\t";
    std::cin >> first_no;
    std::cout << "Enter second number:\t";
    std::cin >> second_no;

    result_add = addition(first_no, second_no);
    result_div = division(first_no, second_no);

    print_results("Addition", result_add);
    print_results("Division", result_div);

    return 0;
}