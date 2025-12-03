#include "parse.h"

#include <climits>
#include <string>

namespace {
bool safe_to_int(const char* s, int& ans)
{
    if (s == nullptr) {
        return false;
    }

    errno = 0;
    char* end = nullptr;
    long val = std::strtol(s, &end, 10);

    if (errno == ERANGE) {
        return false;
    }
    if (end == s || *end != '\0') {
        return false;
    }
    if (val < INT_MIN || val > INT_MAX) {
        return false;
    }

    ans = static_cast<int>(val);
    return true;
}

void parse_3_args(char* argv[], DataStruct::Settings& settings)
{
    int num;

    if (!safe_to_int(argv[1], num)) {
        settings.hasErrors = true;
        return;
    }
    settings.num1 = num;

    if (argv[2][0] == '\0' || argv[2][1] != '\0') {
        settings.hasErrors = true;
        return;
    }
    settings.operation = argv[2][0];

    if (settings.operation != '+' && settings.operation != '-' &&
        settings.operation != '*' && settings.operation != '/' &&
        settings.operation != '^') {
        settings.hasErrors = true;
        return;
    }

    if (!safe_to_int(argv[3], num)) {
        settings.hasErrors = true;
        return;
    }
    settings.num2 = num;
}

void parse_2_args(char* argv[], DataStruct::Settings& settings)
{
    int num;

    if (!safe_to_int(argv[1], num)) {
        settings.hasErrors = true;
        return;
    }
    settings.num1 = num;

    if (argv[2][0] == '\0' || argv[2][1] != '\0') {
        settings.hasErrors = true;
        return;
    }
    settings.operation = argv[2][0];

    if (settings.operation != '!') {
        settings.hasErrors = true;
        return;
    }
}
}  // namespace

namespace Parser {
void parse(int argc, char* argv[], DataStruct::Settings& settings)
{
    switch (argc) {
        // N !
        case 3:
            parse_2_args(argv, settings);
            break;
        // A op B
        case 4:
            parse_3_args(argv, settings);
            break;
        default:
            settings.hasErrors =
                !(argc == 2 && (std::string(argv[1]) == "-h" ||
                                std::string(argv[1]) == "--help"));
            settings.printHelp = true;
            break;
    }
}
}  // namespace Parser