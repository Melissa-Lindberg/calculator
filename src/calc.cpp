#include <cerrno>
#include <climits>
#include <iostream>

int safe_to_int(const char* s)
{
    if (s == nullptr) {
        throw std::runtime_error("String is nullptr");
    }

    errno = 0;
    char* end = nullptr;
    long val = std::strtol(s, &end, 10);

    if (errno == ERANGE) {
        throw std::runtime_error("Number is out of range");
    }
    if (end == s || *end != '\0') {
        throw std::runtime_error("String isn't number");
    }
    if (val < INT_MIN || val > INT_MAX) {
        throw std::runtime_error("Number is out of range");
    }

    return static_cast<int>(val);
}

int factorial_calculation_internal(int num)
{
    if (num == 0 || num == 1) {
        return 1;
    }
    return num * factorial_calculation_internal(num - 1);
}

int factorial_calculation(char* argv[])
{
    if (argv[2][0] == '\0' || argv[2][1] != '\0') {
        throw std::runtime_error("Bad operation");
    }

    int num = safe_to_int(argv[1]);
    if (num < 0) {
        throw std::runtime_error("Number is out of range");
    }

    char op = argv[2][0];
    if (op != '!') {
        throw std::runtime_error("Bad operation");
    }

    return factorial_calculation_internal(num);
}

int pow(int num1, int num2)
{
    if (num2 < 0) {
        throw std::runtime_error("Power must be >= 0");
    }
    if (num2 == 0) {
        if (num1 == 0) {
            throw std::runtime_error("0 to the power 0 is undefined");
        } else {
            return 1;
        }
    }
    int ans = 1;
    int value = num1;
    int power = num2;
    while (power != 0) {
        if (power % 2 == 1) {
            ans *= value;
        }
        power >>= 1;
        value *= value;
    }
    return ans;
}

int opeation_calculation(char* argv[])
{
    if (argv[2][0] == '\0' || argv[2][1] != '\0') {
        throw std::runtime_error("Bad operation");
    }

    int num1 = safe_to_int(argv[1]);
    char op = argv[2][0];
    int num2 = safe_to_int(argv[3]);
    int ans = 0;

    switch (op) {
        case '+':
            ans = num1 + num2;
            break;
        case '-':
            ans = num1 - num2;
            break;
        case '*':
            ans = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                throw std::runtime_error("Division by zero is undefined");
            }
            ans = num1 / num2;
            break;
        case '^':
            ans = pow(num1, num2);
            break;
        default:
            break;
    }
    return ans;
}

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
