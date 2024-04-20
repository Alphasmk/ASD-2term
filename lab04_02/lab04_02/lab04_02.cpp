#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

void quickSort(int* A, int first, int last);

int main()
{
    setlocale(LC_CTYPE, "rus");
    int n, first_place = 0, second_place = 0, third_place = 0, result = 0;
    int* A{};
    do
    {
        cout << "Введите число участников: " << endl;
        cin >> n;
        if (n > 1 && n < 10000)
        {
            A = new int[n];
        }
    } while (n < 1 || n > 10000);

    srand(time(0));

    cout << "Результаты участников: " << endl;
    for (int i = 0; i < n; i++)
    {
        *(A + i) = 1 + rand() % 100;
    }

    quickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << *(A + i) << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        first_place = max(*(A + i), first_place);
    }
    for (int i = 0; i < n; i++)
    {
        if (*(A + i) > second_place && *(A + i) != first_place)
            second_place = *(A + i);
    }

    for (int i = 0; i < n; i++)
    {
        if (*(A + i) > third_place && *(A + i) != first_place && *(A + i) != second_place)
            third_place = *(A + i);
    }


    for (int i = 0; i < n; i++)
        if (*(A + i) == first_place || *(A + i) == second_place || *(A + i) == third_place)
            result++;
    cout << "\nПервое место: " << first_place << " баллов" << endl;
    cout << "Второе место: " << second_place << " баллов" << endl;
    cout << "Третье место: " << third_place << " баллов" << endl;
    cout << "Количество призеров: " << result << endl;
    delete[] A;
}

void quickSort(int* A, int first, int last)
{
    int mid, count;
    int f = first, l = last;
    mid = A[(f + l) / 2];

    do
    {
        while (A[f] < mid) f++;
        while (A[l] > mid) l--;
        if (f <= l)
        {
            count = A[f];
            A[f] = A[l];
            A[l] = count;
            f++;
            l--;
        }
    } while (f < l);

    if (first < l) quickSort(A, first, l);
    if (f < last) quickSort(A, f, last);
}