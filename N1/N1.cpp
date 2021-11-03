#include <iostream>
using namespace std;
int main()
{
	setlocale(0, ""); //Руссифицируем программу программы
	int x;
	cout << "Введи трёхзначное число, в котором цифры не повторяются:" << endl; //Вводим число
	cin >> x;
	bool f = false;
	f = ((x < 100) || (x > 999));
	while (f) //Проверка на дурака
	{
		cout << "Вы ввели неправильное число, введите заново" << endl;
		cin >> x;
		f = ((x < 100) || (x > 999));
	}
	int a;  //Инициализируем переменные
	int b;
	int c;
	a = x % 10; // Запоминание цифр
	b = (x / 10) % 10;
	c = x / 100;
	f = ((a == b) || (a == c) || (b == c) || (x < 100) || (x > 999));
	while (f) //Проверка на дурака
	{
		cout << "Вы ввели неправильное число, введите заново" << endl;
		cin >> x;
		a = x % 10; // Запоминание цифр
		b = (x / 10) % 10;
		c = x / 100;
		f = ((a == b) || (a == c) || (b == c) || (x < 100) || (x > 999));
	}
	cout << "Все полученные числа:" << endl;  //Вывод всех возможных комбинаций
	cout << a << b << c << endl;
	cout << a << c << b << endl;
	cout << b << c << a << endl;
	cout << b << a << c << endl;
	cout << c << a << b << endl;
	cout << c << b << a << endl;
	cout << "Максимальное число: ";
	f = ((a > b) && (a > c));
	if (f)  //Вывод макcимального числа
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
	f = ((b > a) && (b > c));
	if (f)
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
	f = ((c > b) && (c > a));
	if (f)
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
