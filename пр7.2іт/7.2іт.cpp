#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void SwapMinElementsToDiagonal(int** a, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 5;
    int High = 55;
    int n;
    cout << "n = "; cin >> n;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    Create(a, n, Low, High);
    Print(a, n);
    SwapMinElementsToDiagonal(a, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void SwapMinElementsToDiagonal(int** a, const int n)
{
    int* minElements = new int[n]; //мінімальний елемент в кожному рядку
    int* minIndices = new int[n]; //мінімальний індекс елемента

    for (int i = 0; i < n; i++)
    {
        int minElement = a[i][0];
        int minIndex = 0;

        for (int j = 1; j < n; j++)
        {
            if (a[i][j] < minElement)
            {
                minElement = a[i][j];
                minIndex = j;
            }
        }

        minElements[i] = minElement;
        minIndices[i] = minIndex;
    }

    for (int i = 0; i < n; i++)
    {
        int minElement = minElements[i];
        int minIndex = minIndices[i];

        int diagonalElement = a[i][n - 1 - i];

        a[i][n - 1 - i] = minElement;
        a[i][minIndex] = diagonalElement;
    }

    delete[] minElements;
    delete[] minIndices;
}
