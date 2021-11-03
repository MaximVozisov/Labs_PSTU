#include <iostream>
using namespace std;
int main()
{
	setlocale(0, ""); //Руссифицируем вывод программы
	char q, w, e, r, t; //Инициализируем 5 переменных символьного типа
	cout << "Введи 5 символов" << endl; //Вывод сообщения
	cin >> q >> w >> e >> r >> t; //Ввод символов
	cout << t << r << e << w << q; //Вывод символов в обратном порядке
	return 0;
}