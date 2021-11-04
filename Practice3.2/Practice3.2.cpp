#include <iostream>
using namespace std;
int main()
{
	setlocale(0, ""); //Руссифицируем вывод
	int a1, a2, a3, b1, b2, b3, t, h, m, s;
	cout << "Введи время начала в часах, минутах, секундах: ";
	cin >> a1 >> a2 >> a3;
	cout << "Введи время конца в часах, минутах, секундах: ";
	cin >> b1 >> b2 >> b3;
	h = 0;
	m = 0;
	s = 0;
	if (a2 > b2)
	{
		h = h - 1;
		t = a2;
		a2 = b2;
		b2 = t;
		m = 60 - (b2 - a2);
	}
	else
	{
		m = m + (b2 - a2);
	}
	if (a3 > b3)
	{
		m = m - 1;
		t = a3;
		a3 = b3;
		b3 = t;
		s = 60 - (b3 - a3);
	}
	else
	{
		s = s + (b3 - a3);
	}
	h = h + (b1 - a1);
	cout << "Продолжительность: " << h << "ч, " << m << "м, " << s << "c";
	return 0;
}