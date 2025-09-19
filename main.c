#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math_utils.h"

int main(int argc, char *argv[]) {
    char *end;
    int Num4, Num5;
    double Epsi, Num1, Num2, Num3;

    if (argc == 6) {
        Epsi = strtod(argv[2], &end);
        if (*end != '\0') { printf("EPSILON ERROR\n"); return 1; }
        Num1 = strtod(argv[3], &end);
        if (*end != '\0') { printf("NUMBER1 ERROR\n"); return 1; }
        Num2 = strtod(argv[4], &end);
        if (*end != '\0') { printf("NUMBER2 ERROR\n"); return 1; }
        Num3 = strtod(argv[5], &end);
        if (*end != '\0') { printf("NUMBER3 ERROR\n"); return 1; }
    } else if (argc == 4) {
        Num4 = strtod(argv[2], &end);
        if (*end != '\0') { printf("NUMBER1 ERROR\n"); return 1; }
        Num5 = strtod(argv[3], &end);
        if (*end != '\0') { printf("NUMBER2 ERROR\n"); return 1; }
    } else {
        printf("ARGUMENTS ERROR");
        return 1;
    }

    if (strcmp(argv[1], "-q") == 0 || strcmp(argv[1], "/q") == 0) {
        if (argc != 6) { printf("ARGUMENTS ERROR"); return 1; }
        double x1, x2;
        int x = Equation(Epsi, Num1, Num2, Num3, &x1, &x2);
        if (x == 1) {
            printf("%lf\n", x1);
        } else if (x == 2) {
            printf("%lf\n", x1);
            printf("%lf\n", x2);
        } else {
            printf("no answers");
        }
    } else if (strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "/m") == 0) {
        if (argc != 4) { printf("ARGUMENTS ERROR"); return 1; }
        printf(Kratno(Num4, Num5) ? "Kratno\n" : "Ne kratno\n");
    } else if (strcmp(argv[1], "-t") == 0 || strcmp(argv[1], "/t") == 0) {
        if (argc != 6) { printf("ARGUMENTS ERROR"); return 1; }
        printf(Triangle(Epsi, Num1, Num2, Num3) ? "triangle\n" : "Not triangle\n");
    } else {
        printf("FLAG ERROR");
        return 1;
    }
}
