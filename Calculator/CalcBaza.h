#include<iostream>
#include <stack>
#include <cmath>
#include <sstream>
#include "mathFunctions.h"
struct Leksema //���������, ����������� ����� ����� ��� ��������
{
    char type; // 0 ��� �����, "+" ��� �������� �������� � �.�.
    double value; //�������� (������ ��� �����). � �������� �������� ������ "0"
};
int StartCalc();
int getRang(char Ch);
bool Maths(stack<Leksema>& Stack_n, stack<Leksema>& Stack_o,  Leksema& item);