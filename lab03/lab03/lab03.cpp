#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
using namespace std;

void bubbleSort(int*, int);
void insertSort(int*, int);
void choiceSort(int*, int);
void quickSort(int*, int, int);

int main()
{
	setlocale(LC_CTYPE, "rus");

	int N, ogr;
	do
	{
		cout << "Введите N: ";
		cin >> N;
		cout << "Введите ограничение рандомизации чисел(0 - ?): ";
		cin >> ogr;
	} while (N < 1 || ogr < 1);

	int *A = new int[N];
	int *B = new int[N];
	int *C = new int[N];
	int *D = new int[N];
	int *E = new int[N];

	srand(time(0));
	cout << "Изначальный массив: ";
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % ogr;
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
		cout << setw(4) << A[i] << " ";
	}

	cout << endl;

	char choice;

	do
	{
		cout << "1 - Пузырьковой" << endl
			<< "2 - Вставкой" << endl
			<< "3 - Выбора" << endl
			<< "4 - Быстрой" << endl
			<< "5 - Выход" << endl
			<< "Выберите сортировку: ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			{
			bubbleSort(B, N);
			cout << endl;
			break;
			}
		case '2':
			{
			insertSort(C, N);
			cout << endl;
			break;
			}
		case '3':
			{
			choiceSort(D, N);
			cout << endl;
			break;
			}
		case '4':
			{
			auto begin = chrono::steady_clock::now();
			quickSort(E, 0, N - 1);
			auto end = chrono::steady_clock::now();
			for (int i = 0; i < N; i++)
			{
				cout << setw(4) << E[i] << " ";
			}
			auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);
			cout << endl << "Время выполнения: " << elapsed_ms.count() << " нс" << endl;
			cout << endl;
			break;
			}
		case '5':
			{
			delete[] A;
			delete[] B;
			delete[] C;
			delete[] D;
			delete[] E;
			system("pause");
			break;
			}
		}
	} while (choice != '5');
}

void bubbleSort(int* B, int N)
{
	auto begin = chrono::steady_clock::now();
	int temp;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (B[j] > B[j + 1])
			{
				temp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = temp;
			}
		}
	}

	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);

	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << B[i] << " ";
	}

	cout << endl << "Время выполнения: " << elapsed_ms.count() << " нс" << endl;
}

void insertSort(int* C, int N)
{
	auto begin = chrono::steady_clock::now();
	int buff;
	int j;

	for (int i = 1; i < N; i++)
	{
		buff = C[i];
		for (j = i - 1; j >= 0 && C[j] > buff; j--)
		{
			C[j + 1] = C[j];
		}
		C[j + 1] = buff;
	}

	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);

	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << C[i] << " ";
	}

	cout << endl << "Время выполнения: " << elapsed_ms.count() << " нс" << endl;
}

void choiceSort(int* D, int N)
{
	auto begin = chrono::steady_clock::now();
	int min, buf;

	for (int i = 0; i < N; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
		{
			if (D[j] < D[min])
			{
				min = j;
			}
		}

		if (i != min)
		{
			buf = D[i];
			D[i] = D[min];
			D[min] = buf;
		}
	}

	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast<chrono::nanoseconds>(end - begin);

	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << D[i] << " ";
	}

	cout << endl << "Время выполнения: " << elapsed_ms.count() << " нс" << endl;
}

void quickSort(int* E, int first, int last)
{
	int mid, count;
	int f = first, l = last;
	mid = E[(f + l) / 2];

	do
	{
		while (E[f] < mid) f++;
		while (E[l] > mid) l--;
		if (f <= l)
		{
			count = E[f];
			E[f] = E[l];
			E[l] = count;
			f++;
			l--;
		}
	} while (f < l);

	if (first < l) quickSort(E, first, l);
	if (f < last) quickSort(E, f, last);
}