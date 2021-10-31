#include <iostream>
using namespace std;
int main()
{
	setlocale(0, ""); //Руссифицируем программу программы
	int x;
	cout << "Введи трёхзначное число, в котором цифры не повторяются:" << endl; //Вводим число
	cin >> x;
	while ((x < 100) || (x > 999)) //Проверка на дурака
	{
		cout << "Вы ввели неправильное число, введите заново" << endl;
		cin >> x;
	}
	int a;  //Инициализируем переменные
	int b;
	int c;
	a = x % 10; // Запоминание цифр
	b = (x / 10) % 10;
	c = x / 100;
	cout << "1) a=" << a << " b=" << b << " c=" << c << endl;
	while ((a == b) || (a == c) || (b == c) || (x < 100) || (x > 999)) //Проверка на дурака
	{
		cout << "Вы ввели неправильное число, введите заново" << endl;
		cin >> x;
		a = x % 10; // Запоминание цифр
		b = (x / 10) % 10;
		c = x / 100;
		cout << "2) a=" << a << " b=" << b << " c=" << c << endl;
	}
	cout << "Все полученные числа:" << endl;  //Вывод всех возможных комбинаций
	cout << a << b << c << endl;
	cout << a << c << b << endl;
	cout << b << c << a << endl;
	cout << b << a << c << endl;
	cout << c << a << b << endl;
	cout << c << b << a << endl;
	cout << "Максимальное число: ";
	if ((a > b) && (a > c))  //Вывод макчимального числа
	{
		cout << a;
		if (b > c)
		{
			cout << b << c << endl;
		}
		else
		{
			cout << c << b << endl;
		}
	}
	if ((b > a) && (b > c))
	{
		cout << b;
		if (a > c)
		{
			cout << a << c << endl;
		}
		else
		{
			cout << c << a << endl;
		}
	}
	if ((c > b) && (c > a))
	{
		cout << c;
		if (a > b)
		{
			cout << a << b << endl;
		}
		else
		{
			cout << b << a << endl;
		}
	}
	return 0;
}
