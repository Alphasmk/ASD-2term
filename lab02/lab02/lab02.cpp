#include <iostream>
#include <cmath>
using namespace std;

int binarySearch(int A, int B, int X, int count);
void printNumbers(int count);

int buffer[20];

int main()
{
	setlocale(LC_CTYPE, "rus");
	int N, X, size, count = 0, A, B, counter;
	do
	{
		cout << "Введите число N: "; cin >> N;
	} while (N < 1);
	A = 0;
	B = N;
	X = N / 2;
	counter = log(N) / log(2) + 1;
	buffer[count] = X;
	count = binarySearch(A, B, X, count);
	printNumbers(count);
	cout << "Максимальное кол-во шагов = " << counter << endl;
}

int binarySearch(int A, int B, int X, int count)
{
	int choice;
	do
	{
		cout << X << endl;
		cout << "1 - мало" << endl << "2 - много" << endl << "3 - угадал" << endl << "Введите вариант ответа: "; cin >> choice;
		switch (choice)
		{
		case 1:
			A = X;
			X = B - (B - A) / 2;
			count++;
			buffer[count] = X;
			break;
		case 2:
			B = X;
			X = B - (B - A) / 2;
			count++;
			buffer[count] = X;
			break;
		default:
			break;
		}
	} while (choice != 3);
	return count;
}

void printNumbers(int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << buffer[i] << endl;
	}
	cout << "Фактическое количество шагов = " << count << endl;
}