#include <cmath>
#include <stack>
#include <iostream>
#include <sstream>
#include "Leksema.h"
const double Pi = acos(-1); //��������� �������� ����� ��
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
double Tan(double x) { //������� ��� ������� ����������
    double a = cos(x);
    double b = Sin(x);
    return (b / a);
}
double sqrt(double x) {
    double res;
    res = sqrt(x);
    return res;
}
int getRang(char Ch) { //������� ���������� ��������� ��������: "1" ��� �������� � ���������, "2" ��� ��������� � ������� � �.�.
    if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'g' || Ch == 'e')return 4;
    if (Ch == '^')return 3;
    if (Ch == '+' || Ch == '-')return 1;
    if (Ch == '*' || Ch == '/')return 2;
    else return 0;
}
bool Maths(std::stack <Leksema>& Stack_n, std::stack <Leksema>& Stack_o, Leksema& item) { //�������������� �������, ������� ���������� �������
    double a, b, c;
    a = Stack_n.top().value; //������� ������� ����� �� ����� � �������
    Stack_n.pop(); //��������� ������� ����� �� ����� � �������
    switch (Stack_o.top().type) {  //����������� ��� ������� �������� �� ����� � ����������
    case '+': //���� ��� ������� �������� �� ����� � ���������� ��������
        b = Stack_n.top().value;
        Stack_n.pop();
        c = a + b;
        item.type = '0';
        item.value = c;
        Stack_n.push(item); //��������� �������� �������� ������� � ���� � �������
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
            std::cerr << "\n�� 0 ������ ������!\n";
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
            std::cerr << "\n�������� �������� ��� ��������!\n";
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
            std::cerr << "\n�������� �������� ��� ����������!\n";
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
    case 'sq':
        c = sqrt(a);
        item.type = '0';
        item.value = c;
        Stack_n.push(item);
        Stack_o.pop();
        break;
    default:
        std::cerr << "\n������!\n";
        return false;
        break;
    }
    return true;
}
