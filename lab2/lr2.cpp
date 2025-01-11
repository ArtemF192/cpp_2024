#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <conio.h>

#define N 5

using namespace std;

// Функция для нахождения минимума матрицы
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

// Функция для нахождения максимума матрицы
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

// Функция для нахождения максимума нижнетреугольной части матрицы
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

// Функция для нахождения максимума верхнетреугольной части матрицы
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

// Функция для нахождения минимума нижнетреугольной части матрицы
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

// Функция для нахождения минимума верхнетреугольной части матрицы
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

// Функция для нахождения минимума главной диагонали матрицы
float findMinMainDiagonal(float matrix[N][N]) {
    float minVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] < minVal) {
            minVal = matrix[i][i];
        }
    }
    return minVal;
}

// Функция для нахождения максимума главной диагонали матрицы
float findMaxMainDiagonal(float matrix[N][N]) {
    float maxVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        if (matrix[i][i] > maxVal) {
            maxVal = matrix[i][i];
        }
    }
    return maxVal;
}

// Функция для нахождения минимума второстепенной диагонали матрицы
float findMinSecondaryDiagonal(float matrix[N][N]) {
    float minVal = matrix[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (matrix[i][N - 1 - i] < minVal) {
            minVal = matrix[i][N - 1 - i];
        }
    }
    return minVal;
}

// Функция для нахождения максимума второстепенной диагонали матрицы
float findMaxSecondaryDiagonal(float matrix[N][N]) {
    float maxVal = matrix[0][N - 1];
    for (int i = 0; i < N; i++) {
        if (matrix[i][N - 1 - i] > maxVal) {
            maxVal = matrix[i][N - 1 - i];
        }
    }
    return maxVal;
}

// Функция для нахождения среднеарифметического значения элементов матрицы
float findAverage(float matrix[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
    }
    return sum / (N * N);
}

// Функция для нахождения среднеарифметического значения элементов нижнетреугольной части матрицы
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

// Функция для нахождения среднеарифметического значения элементов верхнетреугольной части матрицы
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

// Функция для нахождения сумм строк матрицы
void findRowSums(float matrix[N][N], float rowSums[N]) {
    for (int i = 0; i < N; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < N; j++) {
            rowSums[i] += matrix[i][j];
        }
    }
}

// Функция для нахождения сумм столбцов матрицы
void findColumnSums(float matrix[N][N], float columnSums[N]) {
    for (int j = 0; j < N; j++) {
        columnSums[j] = 0;
        for (int i = 0; i < N; i++) {
            columnSums[j] += matrix[i][j];
        }
    }
}

// Функция для нахождения минимальных значений строк
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

// Функция для нахождения минимальных значений столбцов
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

// Функция для нахождения максимальных значений строк
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

// Функция для нахождения максимальных значений столбцов
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

// Функция для нахождения среднеарифметических значений строк
void findRowAverages(float matrix[N][N], float rowAverages[N]) {
    for (int i = 0; i < N; i++) {
        rowAverages[i] = 0;
        for (int j = 0; j < N; j++) {
            rowAverages[i] += matrix[i][j];
        }
        rowAverages[i] /= N;
    }
}

// Функция для нахождения среднеарифметических значений столбцов
void findColumnAverages(float matrix[N][N], float columnAverages[N]) {
    for (int j = 0; j < N; j++) {
        columnAverages[j] = 0;
        for (int i = 0; i < N; i++) {
            columnAverages[j] += matrix[i][j];
        }
        columnAverages[j] /= N;
    }
}

// Функция для нахождения сумм нижне- и верхнетреугольных частей матрицы
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

// Функция для нахождения элемента, наиболее близкого к среднеарифметическому значению
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

    // Вызов функций и вывод результатов
    cout << "Минимум матрицы: " << findMin(m) << endl;
    cout << "Максимум матрицы: " << findMax(m) << endl;
    cout << "Максимум нижнетреугольной части матрицы: " << findMaxLowerTriangle(m) << endl;
    cout << "Максимум верхнетреугольной части матрицы: " << findMaxUpperTriangle(m) << endl;
    cout << "Минимум нижнетреугольной части матрицы: " << findMinLowerTriangle(m) << endl;
    cout << "Минимум верхнетреугольной части матрицы: " << findMinUpperTriangle(m) << endl;
    cout << "Минимум главной диагонали матрицы: " << findMinMainDiagonal(m) << endl;
    cout << "Максимум главной диагонали матрицы: " << findMaxMainDiagonal(m) << endl;
    cout << "Минимум второстепенной диагонали матрицы: " << findMinSecondaryDiagonal(m) << endl;
    cout << "Максимум второстепенной диагонали матрицы: " << findMaxSecondaryDiagonal(m) << endl;
    cout << "Среднеарифметическое значение элементов матрицы: " << findAverage(m) << endl;
    cout << "Среднеарифметическое значение элементов нижнетреугольной части матрицы: " << findAverageLowerTriangle(m) << endl;
    cout << "Среднеарифметическое значение элементов верхнетреугольной части матрицы: " << findAverageUpperTriangle(m) << endl;

    float rowSums[N], columnSums[N];
    findRowSums(m, rowSums);
    findColumnSums(m, columnSums);
    cout << "Сумма строк матрицы: ";
    for (i = 0; i < N; i++) cout << rowSums[i] << " ";
    cout << endl;
    cout << "Сумма столбцов матрицы: ";
    for (j = 0; j < N; j++) cout << columnSums[j] << " ";
    cout << endl;

    float rowMins[N], columnMins[N];
    findRowMins(m, rowMins);
    findColumnMins(m, columnMins);
    cout << "Минимальные значения строк: ";
    for (i = 0; i < N; i++) cout << rowMins[i] << " ";
    cout << endl;
    cout << "Минимальные значения столбцов: ";
    for (j = 0; j < N; j++) cout << columnMins[j] << " ";
    cout << endl;

    float rowMaxs[N], columnMaxs[N];
    findRowMaxs(m, rowMaxs);
    findColumnMaxs(m, columnMaxs);
    cout << "Максимальные значения строк: ";
    for (i = 0; i < N; i++) cout << rowMaxs[i] << " ";
    cout << endl;
    cout << "Максимальные значения столбцов: ";
    for (j = 0; j < N; j++) cout << columnMaxs[j] << " ";
    cout << endl;

    float rowAverages[N], columnAverages[N];
    findRowAverages(m, rowAverages);
    findColumnAverages(m, columnAverages);
    cout << "Среднеарифметические значения строк: ";
    for (i = 0; i < N; i++) cout << rowAverages[i] << " ";
    cout << endl;
    cout << "Среднеарифметические значения столбцов: ";
    for (j = 0; j < N; j++) cout << columnAverages[j] << " ";
    cout << endl;

    float lowerSum, upperSum;
    findTriangleSums(m, lowerSum, upperSum);
    cout << "Суммы нижнетреугольных частей матрицы: " << lowerSum << endl;
    cout << "Суммы верхнетреугольных частей матрицы: " << upperSum << endl;

    float average = findAverage(m);
    cout << "Элемент, наиболее близкий по значению к среднеарифметическому: " << findClosestToAverage(m, average) << endl;

    _getch();
    return 0;
}