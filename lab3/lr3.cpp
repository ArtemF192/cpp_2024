#include <iostream>
#include <conio.h>
#include <algorithm>
using namespace std;

//void main(void)
//{
//	int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
//	//������� ������� ���. � ����. ���������
//	int imin, imax;
//	//���������� n - ���������� ���������
//	int n = sizeof(mas) / sizeof(int);
//	int i;
//	//��������� ��������� �������� ��� ��� � ����
//	imin = i = 0; imax = i = 0;
//	for (i = 0; i < n; i++)
//		cout << mas[i] << ' ';
//	cout << endl;
//	for (i = 0; i < n - 1; i++)	//���������� ��� � ����
//	{
//		imin = i;
//		for (int j = i + 1; j < n; j++)
//			if (mas[j] < mas[imin]) imin = j;
//		int t = mas[i];
//		mas[i] = mas[imin];
//		mas[imin] = t;
//	}
//	for (i = 0; i < n; i++)	//����� �� �����
//		cout << mas[i] << ' ';
//	cout << endl;
//}

	// ������� ��� ������ ���������
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// ���������� ���������
void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// ������� ����������
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int i = low - 1;

		for (int j = low; j < high; j++) {
			if (arr[j] < pivot) {
				i++;
				swap(arr[i], arr[j]);
			}
		}
		swap(arr[i + 1], arr[high]);

		int pi = i + 1;

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// ���������� �� ����������� ������ � �� �������� ��������
void sortEvenOdd(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] % 2 == 0 && arr[j] % 2 == 0 && arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
			}
			else if (arr[i] % 2 != 0 && arr[j] % 2 != 0 && arr[i] < arr[j]) {
				swap(arr[i], arr[j]);
			}
		}
	}
}

// ���������� �� ��������� �� N1 �� N2 �� �����������
void sortIntervalAsc(int arr[], int N1, int N2) {
	sort(arr + N1, arr + N2 + 1);
}

// ���������� �� ��������� �� N1 �� N2 �� ��������
void sortIntervalDesc(int arr[], int N1, int N2) {
	sort(arr + N1, arr + N2 + 1, greater<int>());
}

// ������� ��� ������ �������
void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() 
{
	setlocale(LC_ALL, "Russian");

	int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
	int size = sizeof(mas) / sizeof(mas[0]);

	cout << "�������� ������: ";
	printArray(mas, size);

	bubbleSort(mas, size);
	cout << "����� ���������� ���������: ";
	printArray(mas, size);

	// ����������� �������� ������ ��� ��������� ����������
	int mas2[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };

	quickSort(mas2, 0, size - 1);
	cout << "����� ������� ����������: ";
	printArray(mas2, size);

	sortEvenOdd(mas, size);
	cout << "����� ���������� ������ �� ����������� � �������� �� ��������: ";
	printArray(mas, size);

	int N1 = 3, N2 = 8;
	sortIntervalAsc(mas, N1, N2);
	cout << "����� ���������� �� ��������� �� " << N1 << " �� " << N2 << " �� �����������: ";
	printArray(mas, size);

	sortIntervalDesc(mas, N1, N2);
	cout << "����� ���������� �� ��������� �� " << N1 << " �� " << N2 << " �� ��������: ";
	printArray(mas, size);

	return 0;
}