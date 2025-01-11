#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <conio.h>

#define N 5

using namespace std;

// ������� ��� ���������� �������� �������
float findMin(float matrix[N][N]) {
    float minVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }
    }
    return minVal;
}

// ������� ��� ���������� ��������� �������
float findMax(float matrix[N][N]) {
    float maxVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// ������� ��� ���������� ��������� ���������������� ����� �������
float findMaxLowerTriangle(float matrix[N][N]) {
    float maxVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// ������� ��� ���������� ��������� ����������������� ����� �������
float findMaxUpperTriangle(float matrix[N][N]) {
    float maxVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    return maxVal;
}

// ������� ��� ���������� �������� ���������������� ����� �������
float findMinLowerTriangle(float matrix[N][N]) {
    float minVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }
    }
    return minVal;
}

// ������� ��� ���������� �������� ����������������� ����� �������
float findMinUpperTriangle(float matrix[N][N]) {
    float minVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        }
    }
    return minVal;
}

// ������� ��� ���������� �������� ������� ��������� �������
float findMinMainDiagonal(float matrix[N][N]) {
    float minVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] < minVal) {
            minVal = matrix[i][i];
        }
    }
    return minVal;
}

// ������� ��� ���������� ��������� ������� ��������� �������
float findMaxMainDiagonal(float matrix[N][N]) {
    float maxVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] > maxVal) {
            maxVal = matrix[i][i];
        }
    }
    return maxVal;
}

// ������� ��� ���������� �������� �������������� ��������� �������
float findMinSecondaryDiagonal(float matrix[N][N]) {
    float minVal = matrix[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (matrix[i][N - 1 - i] < minVal) {
            minVal = matrix[i][N - 1 - i];
        }
    }
    return minVal;
}

// ������� ��� ���������� ��������� �������������� ��������� �������
float findMaxSecondaryDiagonal(float matrix[N][N]) {
    float maxVal = matrix[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (matrix[i][N - 1 - i] > maxVal) {
            maxVal = matrix[i][N - 1 - i];
        }
    }
    return maxVal;
}

// ������� ��� ���������� ��������������������� �������� ��������� �������
float findAverage(float matrix[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
    }
    return sum / (N * N);
}

// ������� ��� ���������� ��������������������� �������� ��������� ���������������� ����� �������
float findAverageLowerTriangle(float matrix[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            sum += matrix[i][j];
            count++;
        }
    }
    return sum / count;
}

// ������� ��� ���������� ��������������������� �������� ��������� ����������������� ����� �������
float findAverageUpperTriangle(float matrix[N][N]) {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum += matrix[i][j];
            count++;
        }
    }
    return sum / count;
}

// ������� ��� ���������� ���� ����� �������
void findRowSums(float matrix[N][N], float rowSums[N]) {
    for (int i = 0; i < N; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < N; j++) {
            rowSums[i] += matrix[i][j];
        }
    }
}

// ������� ��� ���������� ���� �������� �������
void findColumnSums(float matrix[N][N], float columnSums[N]) {
    for (int j = 0; j < N; j++) {
        columnSums[j] = 0;
        for (int i = 0; i < N; i++) {
            columnSums[j] += matrix[i][j];
        }
    }
}

// ������� ��� ���������� ����������� �������� �����
void findRowMins(float matrix[N][N], float rowMins[N]) {
    for (int i = 0; i < N; i++) {
        rowMins[i] = matrix[i][0];
        for (int j = 1; j < N; j++) {
            if (matrix[i][j] < rowMins[i]) {
                rowMins[i] = matrix[i][j];
            }
        }
    }
}

// ������� ��� ���������� ����������� �������� ��������
void findColumnMins(float matrix[N][N], float columnMins[N]) {
    for (int j = 0; j < N; j++) {
        columnMins[j] = matrix[0][j];
        for (int i = 1; i < N; i++) {
            if (matrix[i][j] < columnMins[j]) {
                columnMins[j] = matrix[i][j];
            }
        }
    }
}

// ������� ��� ���������� ������������ �������� �����
void findRowMaxs(float matrix[N][N], float rowMaxs[N]) {
    for (int i = 0; i < N; i++) {
        rowMaxs[i] = matrix[i][0];
        for (int j = 1; j < N; j++) {
            if (matrix[i][j] > rowMaxs[i]) {
                rowMaxs[i] = matrix[i][j];
            }
        }
    }
}

// ������� ��� ���������� ������������ �������� ��������
void findColumnMaxs(float matrix[N][N], float columnMaxs[N]) {
    for (int j = 0; j < N; j++) {
        columnMaxs[j] = matrix[0][j];
        for (int i = 1; i < N; i++) {
            if (matrix[i][j] > columnMaxs[j]) {
                columnMaxs[j] = matrix[i][j];
            }
        }
    }
}

// ������� ��� ���������� �������������������� �������� �����
void findRowAverages(float matrix[N][N], float rowAverages[N]) {
    for (int i = 0; i < N; i++) {
        rowAverages[i] = 0;
        for (int j = 0; j < N; j++) {
            rowAverages[i] += matrix[i][j];
        }
        rowAverages[i] /= N;
    }
}

// ������� ��� ���������� �������������������� �������� ��������
void findColumnAverages(float matrix[N][N], float columnAverages[N]) {
    for (int j = 0; j < N; j++) {
        columnAverages[j] = 0;
        for (int i = 0; i < N; i++) {
            columnAverages[j] += matrix[i][j];
        }
        columnAverages[j] /= N;
    }
}

// ������� ��� ���������� ���� �����- � ����������������� ������ �������
void findTriangleSums(float matrix[N][N], float& lowerSum, float& upperSum) {
    lowerSum = 0;
    upperSum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            lowerSum += matrix[i][j];
        }
        for (int j = i; j < N; j++) {
            upperSum += matrix[i][j];
        }
    }
}

// ������� ��� ���������� ��������, �������� �������� � ��������������������� ��������
float findClosestToAverage(float matrix[N][N], float average) {
    float closest = matrix[0][0];
    float minDiff = fabs(matrix[0][0] - average);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float diff = fabs(matrix[i][j] - average);
            if (diff < minDiff) {
                minDiff = diff;
                closest = matrix[i][j];
            }
        }
    }
    return closest;
}

int main() {
    float m[N][N];
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = rand() / 10.0;
        }
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << setw(8) << setprecision(5) << m[i][j];
        }
        cout << endl;
    }

    setlocale(LC_ALL, "Russian");

    // ����� ������� � ����� �����������
    cout << "������� �������: " << findMin(m) << endl;
    cout << "�������� �������: " << findMax(m) << endl;
    cout << "�������� ���������������� ����� �������: " << findMaxLowerTriangle(m) << endl;
    cout << "�������� ����������������� ����� �������: " << findMaxUpperTriangle(m) << endl;
    cout << "������� ���������������� ����� �������: " << findMinLowerTriangle(m) << endl;
    cout << "������� ����������������� ����� �������: " << findMinUpperTriangle(m) << endl;
    cout << "������� ������� ��������� �������: " << findMinMainDiagonal(m) << endl;
    cout << "�������� ������� ��������� �������: " << findMaxMainDiagonal(m) << endl;
    cout << "������� �������������� ��������� �������: " << findMinSecondaryDiagonal(m) << endl;
    cout << "�������� �������������� ��������� �������: " << findMaxSecondaryDiagonal(m) << endl;
    cout << "�������������������� �������� ��������� �������: " << findAverage(m) << endl;
    cout << "�������������������� �������� ��������� ���������������� ����� �������: " << findAverageLowerTriangle(m) << endl;
    cout << "�������������������� �������� ��������� ����������������� ����� �������: " << findAverageUpperTriangle(m) << endl;

    float rowSums[N], columnSums[N];
    findRowSums(m, rowSums);
    findColumnSums(m, columnSums);
    cout << "����� ����� �������: ";
    for (i = 0; i < N; i++) cout << rowSums[i] << " ";
    cout << endl;
    cout << "����� �������� �������: ";
    for (j = 0; j < N; j++) cout << columnSums[j] << " ";
    cout << endl;

    float rowMins[N], columnMins[N];
    findRowMins(m, rowMins);
    findColumnMins(m, columnMins);
    cout << "����������� �������� �����: ";
    for (i = 0; i < N; i++) cout << rowMins[i] << " ";
    cout << endl;
    cout << "����������� �������� ��������: ";
    for (j = 0; j < N; j++) cout << columnMins[j] << " ";
    cout << endl;

    float rowMaxs[N], columnMaxs[N];
    findRowMaxs(m, rowMaxs);
    findColumnMaxs(m, columnMaxs);
    cout << "������������ �������� �����: ";
    for (i = 0; i < N; i++) cout << rowMaxs[i] << " ";
    cout << endl;
    cout << "������������ �������� ��������: ";
    for (j = 0; j < N; j++) cout << columnMaxs[j] << " ";
    cout << endl;

    float rowAverages[N], columnAverages[N];
    findRowAverages(m, rowAverages);
    findColumnAverages(m, columnAverages);
    cout << "�������������������� �������� �����: ";
    for (i = 0; i < N; i++) cout << rowAverages[i] << " ";
    cout << endl;
    cout << "�������������������� �������� ��������: ";
    for (j = 0; j < N; j++) cout << columnAverages[j] << " ";
    cout << endl;

    float lowerSum, upperSum;
    findTriangleSums(m, lowerSum, upperSum);
    cout << "����� ���������������� ������ �������: " << lowerSum << endl;
    cout << "����� ����������������� ������ �������: " << upperSum << endl;

    float average = findAverage(m);
    cout << "�������, �������� ������� �� �������� � ���������������������: " << findClosestToAverage(m, average) << endl;

    _getch();
    return 0;
}