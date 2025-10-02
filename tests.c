#include <assert.h>
#include <stdio.h>
#include "functions.h"

void test_Kratno() {
    assert(Kratno(5, 10) == 1); 
    assert(Kratno(3, 7) == 0);   
    assert(Kratno(1, 0) == 1);  
}

void test_Equation() {
    double x1, x2;
    int res1 = Equation(1e-6, 1, -5, 6, &x1, &x2);
    assert(res1 == 2);
    assert((x1 == 2 && x2 == 3) || (x1 == 3 && x2 == 2));

    int res2 = Equation(1e-6, 1, 2, 1, &x1, &x2);
    assert(res2 == 1);
    assert(x1 == -1);

    int res3 = Equation(1e-6, 1, 0, 1, &x1, &x2);
    assert(res3 == 0);
}

void test_Triangle() {
    assert(Triangle(1e-6, 3, 4, 5) == 1);  
    assert(Triangle(1e-6, 1, 2, 3) == 0);  
    assert(Triangle(1e-6, 5, 12, 13) == 1); 
}

void run_unit_tests() {
    test_Kratno();
    test_Equation();
    test_Triangle();
    printf("All unit tests passed!\n");
}

int main() {
    run_unit_tests();
    return 0;
}
