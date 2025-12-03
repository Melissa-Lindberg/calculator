#include "runer.h"

#include "calc.h"
#include "parse.h"
#include "print.h"

namespace Run {
int run(int argc, char* argv[])
{
    parse(argc, argv);
    int ans = operatin();
    MyPrint::print_int(ans);
}
}  // namespace Run