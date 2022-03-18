// lab 7.3(1).cpp 
// Опрацювання динамічних багатовимірних масивів 
// Сацик Вікторії
// 20 варіант
// Ітераційний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
bool Part1_Count(int** a, const int rowCount, const int colCount, int& count);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -5;
    int High = -27;
    int rowCount, colCount;
    cout << "rowCount = "; cin >> rowCount;
    cout << "colCount = "; cin >> colCount;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Input(a, rowCount, colCount);
    Print(a, rowCount, colCount);
    int count = 0;
    if (Part1_Count(a, rowCount, colCount, count))
        cout << "count = " << count << endl;
    else
        cout << "there are no zero elements" << endl;
    cout << endl;

}
void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{



    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
        cout << endl;
    }
}
void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}
bool Part1_Count(int** a, const int rowCount, const int colCount, int& count)
{
    bool result = false;
    count = 0;
    int k_zero;
    for (int j = 0; j < colCount; j++)
    {
        k_zero = 0;
        for (int i = 0; i < rowCount; i++)
            if (a[i][j] == 0)
            {
                result = true;
                k_zero++;
                break;
            }
        if (k_zero > 0)
        {
            for (int i = 0; i < rowCount; i++)
                if (a[i][j] > 0)
                    count++;
        }
    }
    return result;
}



