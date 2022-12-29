#include <iostream>
#include <sstream>
#include <cmath>
#include <stack>
#include "Leksema.h"
#include "MathsFunctions.h"
int StartCalculator() {
    setlocale(LC_ALL, "rus");
    while (true) {
        system("cls");
        std::cout << "   Привет! Это программа - калькулятор!\n";
        std::cout << "   Для испрользования числа Пи введите 'p', для использования числа Е введите 'exp(1)'\n";
        std::cout << "   Для испрользования тригонометрических функций используйте запись cos(), sin(), ctg(), tg() \n";
        std::cout << "   Для остановки программы введите Exit \n";
        std::cout << "   Введите выражение: ";
        std::string str;
        getline(std::cin, str);
        std::stringstream sstr{ str };

        char Ch; 
        double value;
        bool flag = true; 
        std::stack<Leksema> Stack_n; 
        std::stack<Leksema> Stack_o; 
        Leksema item; 
        while (true) {
            Ch = sstr.peek(); 
            if (Ch == '\377')break; 
            if (Ch == ' ') { 
                sstr.ignore();
                continue;
            }
            if (Ch == 'E') {
                system("pause");
                return 0;
            }
            if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'e') {
                char foo[3]; 
                for (int i = 0; i < 3; i++) {
                    Ch = sstr.peek();
                    foo[i] = Ch;
                    sstr.ignore();
                }
                if (foo[0] == 's' && foo[1] == 'q' && foo[2] == 'r') {
                    item.type = 'sq';
                    item.value = 0;
                    Stack_o.push(item);
                    continue;
                }
                if (foo[0] == 's' && foo[1] == 'i' && foo[2] == 'n') {
                    item.type = 's';
                    item.value = 0;
                    Stack_o.push(item); 
                    continue;
                }
                if (foo[0] == 'c' && foo[1] == 'o' && foo[2] == 's') { 
                    item.type = 'c';
                    item.value = 0;
                    Stack_o.push(item); 
                    continue;
                }
                if (foo[0] == 't' && foo[1] == 'a' && foo[2] == 'n') { 
                    item.type = 't';
                    item.value = 0;
                    Stack_o.push(item);
                    continue;
                }
                if (foo[0] == 'c' && foo[1] == 't' && foo[2] == 'g') { 
                    item.type = 'g';
                    item.value = 0;
                    Stack_o.push(item);
                    continue;
                }
                if (foo[0] == 'e' && foo[1] == 'x' && foo[2] == 'p') {
                    item.type = 'e';
                    item.value = 0;
                    Stack_o.push(item);
                    continue;
                }
            }
            if (Ch == 'p') { 
                item.type = '0';
                item.value = Pi;
                Stack_n.push(item); 
                flag = 0;
                sstr.ignore();
                continue;
            }
            if (Ch >= '0' && Ch <= '9' || Ch == '-' && flag == 1) {
                sstr >> value;
                item.type = '0';
                item.value = value;
                Stack_n.push(item);
                flag = 0;
                continue;
            }
            if (Ch == '+' || Ch == '-' && flag == 0 || Ch == '*' || Ch == '/' || Ch == '^') { 
                if (Stack_o.size() == 0) { 
                    item.type = Ch;
                    item.value = 0;
                    Stack_o.push(item); 
                    sstr.ignore();
                    continue;
                }
                if (Stack_o.size() != 0 && getRang(Ch) >
                    getRang(Stack_o.top().type)) { 
                    item.type = Ch;
                    item.value = 0;
                    Stack_o.push(item); 
                    sstr.ignore();
                    continue;
                }
                if (Stack_o.size() != 0 && getRang(Ch) <=
                    getRang(Stack_o.top().type)) {
                    if (Maths(Stack_n, Stack_o, item) == false) { 
                        system("pause");
                        return 0;
                    }
                    continue;
                }
            }
            if (Ch == '(') { 
                item.type = Ch;
                item.value = 0;
                Stack_o.push(item); 
                sstr.ignore();
                continue;
            }
            if (Ch == ')') { 
                while (Stack_o.top().type != '(') {
                    if (Maths(Stack_n, Stack_o, item) == false) { 
                        system("pause");
                        return 0;
                    }
                    else continue; 
                }
                Stack_o.pop();
                sstr.ignore();
                continue;
            }
            else { 
                std::cout << "\nНеверно введено выражение!\n";
                system("pause");
                return 0;
            }
        }
        while (Stack_o.size() != 0) { 
            if (Maths(Stack_n, Stack_o, item) == false) {
                system("pause");
                return 0;
            }
            else continue; 
        }
        std::cout << "   Ответ: " << Stack_n.top().value << std::endl; 
        system("pause");
    }
    return 0;
}

int main()
{
    StartCalculator();
    return 0;
}