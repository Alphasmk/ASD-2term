#include <iostream>
#include <chrono>
using namespace std;

float recursiveMethod(int);
float linearMethod(int);

int main()
{
	setlocale(LC_CTYPE, "rus");
	
	int N, x;

	cout << "Введите число N: "; cin >> N;

	auto begin = std::chrono::steady_clock::now();
	cout << linearMethod(N) << endl;
	auto end = std::chrono::steady_clock::now();
	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << "Время выполнения: " << elapsed_ms.count() << " мс" << endl;

	begin = std::chrono::steady_clock::now();
	x = recursiveMethod(N);
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	cout << endl << x << endl;
	cout << "Время выполнения: " << elapsed_ms.count() << " мс" << endl;

	system("pause");
}

float linearMethod(int N)
{
	float A[3] = { 0, 1, 0 };

	for (int i = 2; i < N; i++)
	{
		A[2] = A[0] + A[1];
		for (int k = 0; k < 2; k++)
		{
			A[k] = A[k + 1];
		}
		if (i == N - 1)
		{
			break;
		}
		else
		{
			A[2] = 0;
		}
	}
	return A[2];
}

float recursiveMethod(int N)
{
	if (N == 1)
	{
		return 0;
	}
	else if (N == 2 || N == 3)
	{
		return 1;
	}

	return recursiveMethod(N - 1) + recursiveMethod(N - 2);
}