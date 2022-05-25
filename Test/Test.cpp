#include <iostream>
#include <cmath>
using namespace std;

int sokr(int a, int b)
{
	a = abs(a), b = abs(b);
	if (b == 0) return a;
	else return sokr(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    int x = sokr(a, b);
    a /= x;
    b /= x;
    cout << a << " " << b;
    return 0;
}