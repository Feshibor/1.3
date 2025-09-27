#include "functions.h"
#include <math.h>

int Kratno(int Num1,int Num2){
    if ((Num2 % Num1) == 0) {
        return 1;
    } else {
        return 0;
    }
}

int Equation(double Epsi,double Num1,double Num2,double Num3,double *x1,double *x2){
    double a = Num1;
    double b = Num2;
    double c = Num3;
    if (fabs(a) <= Epsi) {
        if (fabs(b) > Epsi) {
            *x1 = -c / b;
            return 1;
        } else if (fabs(c) <= Epsi) {
            return 0;
        } else {
            return 0;
        }
    }
    double D = (b*b) - 4*a*c;
    if (D > Epsi) {
        *x1 = (-b + sqrt(D)) / (2*a);
        *x2 = (-b - sqrt(D)) / (2*a);
        return 2;
    } else if (fabs(D) <= Epsi) {
        *x1 = -b / (2*a);
        return 1;
    } else {
        return 0;
    }
}

int Triangle(double Epsi,double Num1,double Num2,double Num3){
    if (fabs(Num1*Num1 + Num2*Num2 - Num3*Num3) <= Epsi) {
        return 1;
    } else if (fabs(Num1*Num1 - Num2*Num2 + Num3*Num3) <= Epsi) {
        return 1;
    } else if (fabs(Num3*Num3 + Num2*Num2 - Num1*Num1) <= Epsi) {
        return 1;
    } else {
        return 0;
    }
}
