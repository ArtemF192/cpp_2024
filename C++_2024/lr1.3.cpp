#include <iostream>
using namespace std;
void main(void)
{
	int a = 2, b = 5;
	void obmen1(int, int);
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	cout << "המ מבלוםא: א = " << a << "b = " << b << endl;
	// גûחמג obmen1(int, int);
	cout << "ןמסכו מבלוםא 1: א = " << a << "b = " << b << endl;
	// גûחמג obmen2(int*, int*);
	cout << "ןמסכו מבלוםא 2: א = " << a << "b = " << b << endl;
	// גûחמג obmen3(int&, int&);
	cout << "ןמסכו מבלוםא 3: א = " << a << "b = " << b << endl;
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