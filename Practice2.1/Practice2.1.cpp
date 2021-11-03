#include <iostream>
using namespace std;
int main()
{
    setlocale(0, ""); //Руссифицируем вывод
    int a, b; //Инициализируем переменные целочисленного типа a и b
    cout << "Введите два числа: " << endl; //Вывод сообщения
    cin >> a; //Ввод переменной a
    cin >> b; //Ввод переменной b
    cout << a * b; //Вывод произведения
    return 0;
}