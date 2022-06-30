#include <iostream>
#include <cmath>
using namespace std;

int sokr(int a, int b)
{
	a = abs(a), b = abs(b);
	if (b == 0) return a;
	else return sokr(b, a % b);
}

int NOD(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int NOK(int n1, int n2)
{
    return n1 * n2 / NOD(n1, n2);
}

int main() {
    int a, b;
    cin >> a >> b;
	int nok = NOK(a, b);
	int nod = NOD(a, b);
	cout << nod << endl;
	cout << nok << endl;
    int x = sokr(a, b);
    a /= x;
    b /= x;
    cout << a << " " << b;
    return 0;
}