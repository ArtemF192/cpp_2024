#include <iostream>
#include <locale.h>
using namespace std;
void main(void)
{
	setlocale(LC_ALL, "Russian");

	int number;
	cout << "������� ����� �����: ";
	cin >> number;
	int i, k;
	int power(int, int);
	for (i = 0; i < 10; i++)
	{
		k = power(number, i);
		cout << "i = " << i << ", k = " << k << endl;
	}
}
int power(int x, int n)
{
	int i, p = 1;
	for (i = 0; i < n; i++) p *= x;
	return p;
}