#include <cmath>
#include <stack>
#include <iostream>
#include <sstream>
#include "Leksema.h"
const double Pi = acos(-1); 
double Sin(double x) { 
    return (round(sin(x) * 10000000) / 10000000);
}

double Cos(double x) { 
    return (round(cos(x) * 10000000) / 10000000);
}

double Ctg(double x) { 
    double a = cos(x);
    double b = Sin(x);
    return (a / b);
}
double Tan(double x) { 
    double a = cos(x);
    double b = Sin(x);
    return (b / a);
}
double Sqrt(double x) {
    return sqrt(x);
}
bool negation(double x) {
    if (x == 1) return false;
    else return true;
}
bool conjuction(double x, double y) {
    if (x == 1 && y == 1 || x == 0 && y == 0) {
        return true;
    }
    else return false;
}
bool disjuction(double x, double y) {
    if (x == 0 && y == 0) return false;
    else return true;
}
double Abs(double x) {
    return fabs(x);
}
int getRang(char Ch) {
    if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'g' || Ch == 'e')return 4;
    if (Ch == '^')return 3;
    if (Ch == '+' || Ch == '-')return 1;
    if (Ch == '*' || Ch == '/')return 2;
    else return 0;
}
bool Maths(std::stack <Leksema>& Stack_n, std::stack <Leksema>& Stack_o, Leksema& item) { 
    double a, b, c, f;
    bool d;
    a = Stack_n.top().value; 
    Stack_n.pop();
    if (!Stack_n.empty()) {
        f = Stack_n.top().value;
    }
    switch (Stack_o.top().type) { 
    case '+': 
        b = Stack_n.top().value;
        Stack_n.pop();
        c = a + b;
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '-':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = b - a;
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '^':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = pow(b, a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '*':
        b = Stack_n.top().value;
        Stack_n.pop();
        c = a * b;
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case '/':
        b = Stack_n.top().value;
        if (a == 0) {
            std::cerr << "\nНа 0 делить нельзя!\n";
            return false;
        }
        else {
            Stack_n.pop();
            c = (b / a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;
        }

    case 's':
        c = Sin(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case 'c':
        c = Cos(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;

    case 't':
        if (Cos(a) == 0) {
            std::cerr << "\nНеверный аргумент для тангенса!\n";
            return false;
        }
        else {
            c = Tan(a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;
        }

    case 'g':
        if (Sin(a) == 0) {
            std::cerr << "\nНеверный аргумент для котангенса!\n";
            return false;
        }
        else {
            c = Ctg(a);
            item.type = '0';
            item.value = c;
            Stack_n.push(item);
            Stack_o.pop();
            break;
        }

    case 'e':
        c = exp(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;
    case 'S':
        if (a < 0) {
            std::cerr << "\nОшибка!\n";
            return false;
            break;
        }
        else
        c = Sqrt(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;
    case 'n':
        d = negation(a);
        item.type = '0';
        item.value = a;
        item.logic = d;
        Stack_n.push(item);
        Stack_o.pop();
        break;
    case 'C':
        d = conjuction(a, f);
        item.type = '0';
        item.value = 0;
        item.logic = d;
        Stack_n.push(item);
        Stack_o.pop();
        break;
    case 'd':
        d = disjuction(a, f);
        item.type = '0';
        item.value = 0;
        item.logic = d;
        Stack_n.push(item);
        Stack_o.pop();
        break;
    case 'a':
        c = Abs(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;
    default:
        std::cerr << "\nОшибка!\n";
        return false;
        break;
    }
    return true;
}
