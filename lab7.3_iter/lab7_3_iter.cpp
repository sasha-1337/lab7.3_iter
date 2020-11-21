#include <iostream>
#include <Windows.h>
#include <time.h>
#include <iomanip>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
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

int Part1_Count(int** a, const int rowCount, const int colCount)
{
	int k_zero = 0;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			if (a[i][j] == 0)
			{
				k_zero++;
				break;
			}
	}
	return k_zero;
}

void Num_Col(int** a, const int rowCount, const int colCount) 
{
	int m = 0; // ����� � ������
	int col = 0; // ����� �������
	for (int j = 0; j < colCount; j++) 
	{
		int count = 0; // ������� ��������� �����
		for (int i = 0; i < rowCount; i++)
			for (int k = i + 1; k < rowCount; k++)
				if (a[i][j] == a[k][j])
					count++;
		if (count >= m) {
			m = count;
			col = j;
			cout << " ����� ������� � ���� ��������: " << col << endl << endl;
		}
		if (count < m) {
			m = count;
			col = j;
			cout << " ��������, ���� �� ���������� ����: " << col << endl << endl;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));

	int Low = -5;
	int High = 5;

	int rowCount = 0;
	int colCount = 0;
	cout << " ʳ������ �����: "; cin >> rowCount; // k
	cout << " ʳ������ ��������: "; cin >> colCount; // n

	int** a = new int* [rowCount];
	for (int i = 0; i < colCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	cout << " ʳ������ ����� � ������� ���������: " << Part1_Count(a, rowCount, colCount) << endl;

	Num_Col(a, rowCount, colCount);

	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}