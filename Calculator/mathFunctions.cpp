#include <iostream>
#include "CalcBaza.h"
#include <stack>
#include <sstream>
#include <cmath>

double Sin(double x) { //Функция для округления значение синуса
    return (round(sin(x) * 10000000) / 10000000);
}

double Cos(double x) { //Функция для округления значение косинуса
    return (round(cos(x) * 10000000) / 10000000);
}

double Ctg(double x) { //Функция для расчета котангенса
    double a = cos(x);
    double b = Sin(x);
    return (a / b);
}