#include <stdio.h>
#include "functions.h"

int main(void) {
    // Тест -m
    printf("-m 2 4: %s\n", Kratno(2, 4) ? "Kratno" : "Ne kratno");
    printf("-m 3 7: %s\n", Kratno(3, 7) ? "Kratno" : "Ne kratno");

    // Тест -q
    double x1, x2;
    double eps = 0.4;
    double a = 0.2, b = 0.4, c = 0.5;
    int res = Equation(eps, a, b, c, &x1, &x2);
    printf("-q 0.4 0.2 0.4 0.5: ");
    if (res == 1) printf("%lf\n", x1);
    else if (res == 2) printf("%lf %lf\n", x1, x2);
    else printf("no answers\n");

    // Тест -t
    eps = 0.001;
    printf("-t 3 4 5: %s\n", Triangle(eps, 3, 4, 5) ? "triangle" : "Not triangle");
    printf("-t 1 2 5: %s\n", Triangle(eps, 1, 2, 5) ? "triangle" : "Not triangle");

    return 0;
}
