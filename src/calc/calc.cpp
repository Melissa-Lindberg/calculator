#include "calc.h"

#include "my_math.h"

namespace Сalculation {
int calculation(DataStruct::Settings &settings)
{
    int ans = 0;
    switch (settings.operation) {
        case '+':
            settings.hasErrors =
                !MyMath::sum_calculation(settings.num1, settings.num2, ans);
            break;
        case '-':
            settings.hasErrors = !MyMath::difference_calculation(
                settings.num1, settings.num2, ans);
            break;
        case '*':
            settings.hasErrors =
                !MyMath::product_calculation(settings.num1, settings.num2, ans);
            break;
        case '/':
            settings.hasErrors = !MyMath::division_calculation(
                settings.num1, settings.num2, ans);
            break;
        case '^':
            settings.hasErrors =
                !MyMath::pow_calculation(settings.num1, settings.num2, ans);
            break;
        case '!':
            settings.hasErrors =
                !MyMath::factorial_calculation(settings.num1, ans);
            break;
        default:
            settings.hasErrors = true;
            break;
    }
    return ans;
}
}  // namespace Сalculation
