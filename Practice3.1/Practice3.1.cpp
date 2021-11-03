#include <iostream>
using namespace std;
int main()
{
	setlocale(0, ""); //Руссифицируем вывод
	int d; //Инициализируем переменную целочисленного типа d
	cout << "Введи *F" << endl; //Вывод сообщения
	cin >> d; //Ввод данных
	cout << d << "*F = " << (5 * (d - 32)) / 9 << "*C"; //Вывод данных
	return 0;
}