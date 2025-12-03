#include "runer.h"

#include "calc.h"
#include "date_structs.h"
#include "parse.h"
#include "print.h"

namespace Run {
int run(int argc, char* argv[])
{
    DataStruct::Settings settings = {false, false, 0, 0, 0};
    int ans = 0;

    Parser::parse(argc, argv, settings);
    if (!settings.hasErrors && !settings.printHelp) {
        ans = Сalculation::calculation(settings);
    }
    MyPrint::print_result(ans, settings.hasErrors, settings.printHelp);
    return settings.hasErrors ? 1 : 0;
}
}  // namespace Run