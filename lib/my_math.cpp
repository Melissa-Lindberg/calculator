#include "math.h"

#include <cerrno>
#include <climits>
#include <stdexcept>

static int safe_to_int(const char* s)
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

static int pow(int num1, int num2)
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

static int factorial_calculation_internal(int num)
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