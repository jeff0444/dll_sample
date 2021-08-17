#include <stdio.h>
#include "my_math_class_c.h"

int main()
{
    int a = 10;
    int b = 20;
    newNumber a_val;
    int i,j;

    math_class math_cls = math_class(a);
    printf("a.i, a.j %d, %d\n", math_cls.a.i, math_cls.a.j);

    math_cls.get_a(a_val);
    printf("get_a %d, %d\n", a_val.i, a_val.j);

    math_cls.Add(b);
    math_cls.get_a(a_val);
    printf("Add(b) %d, %d\n", a_val.i, a_val.j);

    math_cls.Subtraction(b);
    math_cls.get_a(a_val);
    printf("Subtraction(b) %d, %d\n", a_val.i, a_val.j);

    math_cls.Multiply(b);
    math_cls.get_a(a_val);
    printf("Multiply(b) %d, %d\n", a_val.i, a_val.j);

    printf("\n");
    
    // ============  use LoadLibraryA()  =============================================
    printf("====  use LoadLibraryA()\n");
    type_math_handle p_math_cls = createMathClass_C(a);
    get_a_C(p_math_cls, i, j);
    printf("get_a_C %d, %d\n", i, j);

    Add_C(p_math_cls, b);
    get_a_C(p_math_cls, i, j);
    printf("Add_C %d, %d\n", i, j);

    Subtraction_C(p_math_cls, b);
    get_a_C(p_math_cls, i, j);
    printf("Subtraction_C %d, %d\n", i, j);

    Multiply_C(p_math_cls, b);
    get_a_C(p_math_cls, i, j);
    printf("Multiply_C %d, %d\n", i, j);

    destroyMathClass_C(p_math_cls);

    return 0;
}