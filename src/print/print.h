#pragma once

#include <iostream>

namespace {
void print_help()
{
    std::cout << "Calculator Utility\n"
                 "Options:\n"
                 "  -h, --help   Show this help message\n"
                 "\n"
                 "Usage:\n"
                 "  ./calc <num1> <op> <num2>\n"
                 "  ./calc <num> !\n"
                 "\n"
                 "Supported operations:\n"
                 "  +   Addition (num1 + num2)\n"
                 "  -   Subtraction (num1 - num2)\n"
                 "  *   Multiplication (num1 * num2)\n"
                 "  /   Division (num1 / num2)\n"
                 "  ^   Power (num1 ^ num2)\n"
                 "  !   Factorial (num !)\n"
                 "\n"
                 "Examples:\n"
                 "  ./calc 5 + 3\n"
                 "  ./calc 10 / 2\n"
                 "  ./calc 2 ^ 8\n"
                 "  ./calc 6 !\n";
}
}  // namespace

namespace MyPrint {

void print_result(int num, bool hasError, bool printHelp)
{
    if (printHelp || hasError) {
        print_help();
    } else {
        std::cout << num << std::endl;
    }

    std::cout << "Error code: " << (hasError ? 1 : 0) << std::endl;
}

}  // namespace MyPrint