#include <iostream>
using namespace std;
void main(void)
{
	int a = 2, b = 5;
	void obmen1(int, int);
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	cout << "�� ������: � = " << a << "b = " << b << endl;
	// ����� obmen1(int, int);
	cout << "����� ������ 1: � = " << a << "b = " << b << endl;
	// ����� obmen2(int*, int*);
	cout << "����� ������ 2: � = " << a << "b = " << b << endl;
	// ����� obmen3(int&, int&);
	cout << "����� ������ 3: � = " << a << "b = " << b << endl;
}

void obmen1(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void obmen2(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void obmen3(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}