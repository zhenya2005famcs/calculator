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
        std::cout << "   Для испрользования числа Пи введите 'p', для использования числа Е введите 'exp(1)'\n";
        std::cout << "   Для испрользования тригонометрических функций пользуйтесь записью cos(), sin(), ctg(), tg() \n";
        std::cout << "   Для вычисления корня используйте запись sqr() \n";
        std::cout << "   Чтобы вычислить модуль числа используйте abs() \n";
        std::cout << "   Для использования логических функций пользуйтесь записью neg(1 or 0), dis(1 1), con(0 0) \n";
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
                return 0;
            }
            if (Ch == 's') {
                char foo[4];
                for (int i = 0; i < 4; i++) {
                    Ch = sstr.peek();
                    foo[i] = Ch;
                    sstr.ignore();
                }
                if (foo[0] == 's' && foo[1] == 'q' && foo[2] == 'r' && foo[3] == 't') {
                    item.type = 'S';
                    item.value = 0;
                    Stack_o.push(item);
                    continue;
                }
            }

            if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'e' || Ch == 'n' || Ch == 'd' || Ch == 'c' || Ch == 'a') {
                char foo[3]; 
                for (int i = 0; i < 3; i++) {
                    Ch = sstr.peek();
                    foo[i] = Ch;
                    sstr.ignore();
                }
                if (foo[0] == 'a' && foo[1] == 'b' && foo[2] == 's') {
                    item.type = 'a';
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
                if (foo[0] == 'n' && foo[1] == 'e' && foo[2] == 'g') {
                    item.type = 'n';
                    item.value = 0;
                    Stack_o.push(item);
                    continue;
                }
                if (foo[0] == 'c' && foo[1] == 'o' && foo[2] == 'n') {
                    item.type = 'C';
                    item.value = 0;
                    Stack_o.push(item);
                    continue;
                }
                if (foo[0] == 'd' && foo[1] == 'i' && foo[2] == 's') {
                    item.type = 'd';
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
            if (Ch == '0') {
                sstr >> value;
                item.type = '0';
                item.value = value;
                item.logic = false;
                Stack_n.push(item);
                flag = 0;
                continue;
            }
            if (Ch == '1') {
                sstr >> value;
                item.type = '0';
                item.value = value;
                item.logic = true;
                Stack_n.push(item);
                flag = 0;
                continue;
            }
            if (Ch > '1' && Ch <= '9' || Ch == '-' && flag == 1) {
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
        if (Stack_n.top().value == 1 || Stack_n.top().value == 0) {
            std::cout << " Значение: " << Stack_n.top().value << ",  Логическое значение: " << Stack_n.top().logic << std::endl;
        } else
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