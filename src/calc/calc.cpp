#include <iostream>

#include "my_math.h"

static void print_help()
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

int main(int argc, char* argv[])
{
    int ret = 1;
    switch (argc) {
        // N!
        case 3:
            std::cout << factorial_calculation(argv) << std::endl;
            ret = 0;
            break;
        // A op B
        case 4:
            std::cout << opeation_calculation(argv) << std::endl;
            ret = 0;
            break;
        default:
            if (argc == 2 && (std::string(argv[1]) == "-h" ||
                              std::string(argv[1]) == "--help")) {
                ret = 0;
            }
            print_help();
            break;
    }
    std::cout << "Error code: " << ret << std::endl;
    return ret;
}

// 1 + 1 // 3 + 1 = 4
// 2 ^ 3 // 3 + 1 = 4
// 10 ! // 2 + 1 = 3
// -h --help // 1 + 1 = 2
