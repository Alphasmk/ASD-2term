#include <iostream>
#include <ctime>
using namespace std;

void fill(int*, int, int);
void sort(int*, int);
int findSum(int*, int);

int main()
{
	setlocale(LC_CTYPE, "rus");
	int N;
	do
	{
		cout << "Введите количество товаров: ";
		cin >> N;
	} while (N < 1 || N > 10000);

	int random;
	do
	{
		cout << "Введите максимальную цену товара: ";
		cin >> random;
	} while (random < 1);

	int *A = new int[N];
	fill(A, N, random);

	cout << "Изначальный массив: ";
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	sort(A, N);

	cout << "Один из вариантов порядка пробивания: ";
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl << findSum(A, N) << " - максимальная сумма чека" << endl;

	delete[] A;
}

void fill(int *A, int N, int random)
{
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % (random - 1) + 1;
	}
}

void sort(int* A, int N)
{
	int min, max, buf, pointermax, pointermin;
	if (N % 2 != 0)
	{
		N -= 1;
	}

	for (int i = 0; i < N; i = i + 2)
	{
		max = A[i];
		min = A[i + 1];
		pointermax = i;
		pointermin = i + 1;
		for (int k = i + 2; k < N; k++)
		{
			if (A[k] > max)
			{
				max = A[k];
				pointermax = k;
			}

			if (A[k] < min)
			{
				min = A[k];
				pointermin = k;
			}
		}
			buf = A[pointermax];
			A[pointermax] = A[i];
			A[i] = buf;

			buf = A[pointermin];
			A[pointermin] = A[i + 1];
			A[i + 1] = buf;
	}

	if (A[N - 1] > A[N - 2] && N % 2 == 0)
	{
		buf = A[N - 1];
		A[N - 1] = A[N - 2];
		A[N - 2] = buf;
	}
}

int findSum(int* A, int N)
{
	int sum = 0;
	bool is = false;

	if (N % 2 != 0)
	{
		sum += A[N];
	}

	for (int i = 0; i < N; i += 2)
	{
		sum += A[i];
	}

	return sum;
}