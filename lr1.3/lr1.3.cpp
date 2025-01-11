#include <iostream>
using namespace std;

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

void main(void)
{
    setlocale(LC_ALL, "Russian");

    int a = 2, b = 5;
    cout << "до обмена: а = " << a << " b = " << b << endl;

    obmen1(a, b);
    cout << "после обмена 1: а = " << a << " b = " << b << endl;

    obmen2(&a, &b);
    cout << "после обмена 2: а = " << a << " b = " << b << endl;

    obmen3(a, b);
    cout << "после обмена 3: а = " << a << " b = " << b << endl;
}