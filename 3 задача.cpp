// Условие задачи: Описать функцию sin1(x, e) вещественного типа, находящую приближенное хначение функции 
// sin(x): sin(x)=x-x^3/(3!)+x^5/(5!)-...+(-1)^n * x^(2*n+1)/((2*n+1)!)+... В сумме учитывать все слагаемые, модуль которых больше e.
#include <iostream>
#include <cmath>
using namespace std;
float fact(int a)
{
	int res = 1;
	for (int i = 1; i <= a; i++)
	{
		res = res * i;
	}
	return res;
}

void sin1(float x, float eps)
{
	float xi = x, ni = 1, S = 0, a = x;
	int i = 1, znak = 1;
	while (abs(a) > eps)
	{
		a = xi / ni;
		S += znak * a;
		znak *= -1;
		xi = xi * xi * xi;
		ni = fact(2 * i + 1);
		i++;
	}
	cout << S;
}

int main()
{
	float x;
	cout << "X: ";
	cin >> x;
	for (int i = 0; i < 6; i++)
	{
		float e;
		cout << endl;
		cout << "e = ";
		cin >> e;
		sin1(x, e);
	}
}