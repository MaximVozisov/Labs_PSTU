﻿#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() 
{
    setlocale(0, ""); //Руссифицируем вывод программы
    srand(time(0)); //Генерируем число через время
    int x;
    x = (rand() % 100) + 1;
    cout << "Игра: угадай число от 1 до 100\nУ тебя 6 попыток\nВведи число:\n";
    int z;
    cin >> z; //Ввод числа пользователем
    int n = 5;
    bool f = false;
    f = ((z != x) && (n != 0));
    while (f) //Проверяется условия, при которых пользователь угадывает или не угадывает число
    {
        if (z > x) //Анализ введённого числа пользователем
        {
            cout << "Вы ввели число больше нужного...\n";
        }
        else
        {
            cout << "Вы ввели число меньше нужного...\n";
        }
        cout << "Попробуйте ещё раз\nУ Вас ещё " << n << " попыток!\n";
        cin >> z;
        n = n - 1; //Счётчик попыток
        f = ((z != x) && (n != 0));
    }
    if (z == x) //Проверяется условия, при которых пользователь угадывает или не угадывает число
    {
        cout << "Вы угадали число!!! Поздравляем!!!";
    }
    else
    {
        cout << "Вы не справились, попробуйте снова...\nЗагаданное число: " << x;
    }
    return 0;
}
