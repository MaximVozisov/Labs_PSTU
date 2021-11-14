#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	setlocale(0, "");
	cout << "Задание 1 (float):" << endl;
	float a = 1000;
	float b = 0.0001;
	float q, w, e, r;
	q = a - b;
	cout << "a - b = " << q << endl;
	w = pow(q, 3);
	cout << "(a-b)^3 = " << w << endl;
	q = pow(a, 3) - 3 * pow(b, 2) * a;
	cout << "a^3 - 3 * b^2 * a = " << q << endl;
	w = w - q;
	cout << "(a-b)^3 - a^3 - 3 * b^2 * a = " << w << endl;
	q = pow(b, 3);
	cout << "b^3 = " << q << endl;
	e = 3 * pow(a, 2) * b;
	cout << "3 * a^2*b = " << e << endl;
	q = q - e;
	cout << "b^3 - 3 * a^2*b = " << q << endl;
	r = w / q;
	cout << "Значение выражения = " << r << endl;
	cout << "Задание 1 (double):" << endl;
	double a1 = 1000;
	double b1 = 0.0001;
	double q1, w1, e1, r1;
	q1 = a1 - b1;
	cout << "a - b = " << q1 << endl;
	w1 = pow(q1, 3);
	cout << "(a-b)^3 = " << w1 << endl;
	q1 = pow(a1, 3) - 3 * pow(b1, 2) * a1;
	cout << "a^3 - 3 * b^2 * a = " << q1 << endl;
	w1 = w1 - q1;
	cout << "(a-b)^3 - a^3 - 3 * b^2 * a = " << w1 << endl;
	q1 = pow(b1, 3);
	cout << "b^3 = " << q1 << endl;
	e1 = 3 * pow(a1, 2) * b1;
	cout << "3 * a^2*b = " << e1 << endl;
	q1 = q1 - e1;
	cout << "b^3 - 3 * a^2*b = " << q1 << endl;
	r1 = w1 / q1;
	cout << "Значение выражения = " << r1 << endl;
	cout << "Задание 2:" << endl;
	int m = 0;
	int n = 0;
	cout << "1) " << m - ++n << endl;
	cout << "2) " << (++m > --n) << endl;
	cout << "3) " << (--n < ++m) << endl;
	return 0;
}