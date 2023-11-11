
// Lab_7_1.cpp
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** T, const int rowCount, const int colCount, const int Low,
    const int High, int i, int j);
void Print(int** T, const int rowCount, const int colCount, int i, int j);
void Sort(int** T, const int rowCount, const int colCount, int i0 = 0, int i1 = 0);
void Change(int** T, const int row1, const int row2, const int colCount);
void Calc(int** T, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0);

void Create(int** a, const int rowCount, const int colCount,
    const int Low, const int High, int i, int j)
{
    a[i][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1)
        Create(a, rowCount, colCount, Low, High, i, j + 1);
    else
        if (i < rowCount - 1)
            Create(a, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << a[i][j];
    if (j < colCount - 1)
        Print(a, rowCount, colCount, i, j + 1);
    else
        if (i < rowCount - 1)
        {
            cout << endl;
            Print(a, rowCount, colCount, i + 1, 0);
        }
        else
            cout << endl << endl;
}

void Sort(int** T, const int rowCount, const int colCount, int i0, int i1) {
    if (i0 < rowCount - 1) {
        if (i1 < rowCount - i0 - 1) {
            if ((T[i1][0] > T[i1 + 1][0]) ||
                (T[i1][0] == T[i1 + 1][0] && T[i1][1] < T[i1 + 1][1]) ||
                (T[i1][0] == T[i1 + 1][0] && T[i1][1] == T[i1 + 1][1] && T[i1][2] > T[i1 + 1][2])) {
                Change(T, i1, i1 + 1, colCount, 0);
            }
            Sort(T, rowCount, colCount, i0, i1 + 1);
        }
        else {
            Sort(T, rowCount, colCount, i0 + 1, 0);
        }
    }
    Sort(T, rowCount, colCount, 0, 0);
}


void Change(int** T, const int row1, const int row2, const int colCount, int j)
{

    if (j < colCount)
    {
        int tmp = T[row1][j];
        T[row1][j] = T[row2][j];
        T[row2][j] = tmp;
        Change(T, row1, row2, colCount, j + 1);
    }
}
void Calc(int** T, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (i >= rowCount)
        return;

    if (j >= colCount)
    {
        Calc(T, rowCount, colCount, S, k, i + 1, 0);
        return;
    }

    if (!(T[i][j] > 0 && T[i][j] % 5 == 0))
    {
        S += T[i][j];
        k++;
        T[i][j] = 0;
    }

    Calc(T, rowCount, colCount, S, k, i, j + 1);
}

int main()
{
    srand((unsigned)time(NULL));
    int Low = -42;
    int High = 51;
    int rowCount = 7;
    int colCount = 6;
    int** T = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        T[i] = new int[colCount];
    Create(T, rowCount, colCount, Low, High, 0, 0);
    Print(T, rowCount, colCount, 0, 0);
    Sort(T, rowCount, colCount, 0, 0);
    Print(T, rowCount, colCount, 0, 0);
    int S = 0;
    int k = 0;
    Calc(T, rowCount, colCount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    Print(T, rowCount, colCount, 0, 0);
    for (int i = 0; i < rowCount; i++)
        delete[] T[i];
    delete[] T;
    return 0;
}