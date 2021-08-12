
#include <stdio.h>

#include "my_math_class.h"

int main()
{
    int a = 10;
    int b = 20;

    std::shared_ptr<math_class> math_cls = createMathClass(10);
    printf("get_a %d\n", math_cls->get_a());

    math_cls->Add(b);
    printf("Add(b) %d\n", math_cls->get_a());

    math_cls->Subtraction(b);
    printf("Subtraction(b) %d\n", math_cls->get_a());

    math_cls->Multiply(b);
    printf("Multiply(b) %d\n", math_cls->get_a());

    return 0;
}