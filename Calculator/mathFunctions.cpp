#include <iostream>
#include "CalcBaza.h"
#include <stack>
#include <sstream>
#include <cmath>

double Sin(double x) { //������� ��� ���������� �������� ������
    return (round(sin(x) * 10000000) / 10000000);
}

double Cos(double x) { //������� ��� ���������� �������� ��������
    return (round(cos(x) * 10000000) / 10000000);
}

double Ctg(double x) { //������� ��� ������� ����������
    double a = cos(x);
    double b = Sin(x);
    return (a / b);
}