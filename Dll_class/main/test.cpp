#include <stdio.h>
#include "my_math_class.h"

int main()
{
    int a = 10;
    int b = 20;
    int i,j;

    // ============  use std::shared_ptr  =============================================
    printf("====  use std::shared_ptr\n");
    std::shared_ptr<math_class> math_cls = createMathClass(a);
    math_cls->get_a(i, j);
    printf("get_a %d %d\n", i, j);
    printf("get_a_i %d\n", math_cls->get_a_i());

    math_cls->Add(b);
    math_cls->get_a(i, j);
    printf("Add(b) %d %d\n", i, j);

    math_cls->Subtraction(b);
    math_cls->get_a(i, j);
    printf("Subtraction(b) %d %d\n", i, j);

    math_cls->Multiply(b);
    math_cls->get_a(i, j);
    printf("Multiply(b) %d %d\n", i, j);

    math_cls.reset();
    printf("\n");

    // ============  use c pointer  =============================================
    printf("====  use c pointer\n");
    math_class *p_math_cls = createMathClass_pointer(a);
    p_math_cls->get_a(i, j);
    printf("get_a %d %d\n", i, j);
    printf("get_a_i %d\n", p_math_cls->get_a_i());

    p_math_cls->Add(b);
    p_math_cls->get_a(i, j);
    printf("Add(b) %d %d\n", i, j);

    p_math_cls->Subtraction(b);
    p_math_cls->get_a(i, j);
    printf("Subtraction(b) %d %d\n", i, j);

    p_math_cls->Multiply(b);
    p_math_cls->get_a(i, j);
    printf("Multiply(b) %d %d\n", i, j);

    delete p_math_cls;
    printf("\n");

    // ============  use LoadLibraryA()  =============================================
    printf("====  use LoadLibraryA()\n");
    type_math_handle h_math_cls = createMathClass_C(a);
    get_a_C(h_math_cls, i, j);
    printf("get_a_C %d %d\n", i, j);

    Add_C(h_math_cls, b);
    get_a_C(h_math_cls, i, j);
    printf("Add_C %d %d\n", i, j);

    Subtraction_C(h_math_cls, b);
    get_a_C(h_math_cls, i, j);
    printf("Subtraction_C %d %d\n", i, j);

    Multiply_C(h_math_cls, b);
    get_a_C(h_math_cls, i, j);
    printf("Multiply_C %d %d\n", i, j);

    destroyMathClass_C(h_math_cls);
    return 0;
}