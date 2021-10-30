#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    setlocale(0, "");
    srand(time(0));
    int x;
    x = (rand() % 6) + 1;
    cout << "Игра: угадай число от 1 до 100\nУ тебя 6 попыток\nВведи число:\n";
    int z;
    cin >> z;
    int n=5;
    while ((z != x)&&(n!=0))
    {
        if (z > x)
        {
            cout << "Вы ввели число больше нужного...\n";
        }
        else
        {
            cout << "Вы ввели число меньше нужного...\n";
        }
        cout << "Попробуйте ещё раз\nУ Вас ещё " << n << " попыток!\n";
        cin >> z;
        n = n - 1;
    }
    if (z == x)
    {
        cout << "Вы угадали число!!! Поздравляем!!!";
    }
    else
    {
        cout << "Вы не справились, попробуйте снова...\nЗагаданное число: " << x;
    }
    return 0;
}
