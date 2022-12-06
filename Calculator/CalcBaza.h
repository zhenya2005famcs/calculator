#include<iostream>
#include <stack>
#include <cmath>
#include <sstream>
#include "mathFunctions.h"
struct Leksema //—труктура, описывающа€ любое число или операцию
{
    char type; // 0 дл€ чисел, "+" дл€ операции сложени€ и т.д.
    double value; //«начение (только дл€ чисел). ” операций значение всегда "0"
};
int StartCalc();
int getRang(char Ch);
bool Maths(stack<Leksema>& Stack_n, stack<Leksema>& Stack_o,  Leksema& item);