#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void FindRowWithLongestSeries(int** arr, int rowCount, int colCount, int i, int j, int currentSeriesLength, int& rowWithLongestSeries, int& maxSeriesLength);
int countColumnsWithZero(int** a, int numRows, int numColumns, int j, int i, int count, bool Haszero);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < colCount - 1)
		PrintRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	PrintRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		PrintRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void InputRow(int** a, const int rowNo, const int colCount, int colNo)
{
	cout << "a[" << rowNo << "][" << colNo << "] = ";
	cin >> a[rowNo][colNo];
	if (colNo < colCount - 1)
		InputRow(a, rowNo, colCount, colNo + 1);
	else
		cout << endl;
}
void InputRows(int** a, const int rowCount, const int colCount, int rowNo)
{
	InputRow(a, rowNo, colCount, 0);
	if (rowNo < rowCount - 1)
		InputRows(a, rowCount, colCount, rowNo + 1);
	else
		cout << endl;
}
void CreateRow(int** a, const int rowNo, const int colCount,
	const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);
}
void CreateRows(int** a, const int rowCount, const int colCount,
	const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);
}

int main()
{
	srand((unsigned)time(NULL));
	int Low = -7;
	int High = 7;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	 CreateRows(a, rowCount, colCount, Low, High, 0);
	InputRows(a, rowCount, colCount, 0);
	PrintRows(a, rowCount, colCount, 0);

	int count = countColumnsWithZero(a, rowCount, colCount, 0, 0, 0, false);
	int longestSeriesRow = -1;
	int maxSeriesLength = 0;
	FindRowWithLongestSeries(a, rowCount, colCount, 0, 0, 1, longestSeriesRow, maxSeriesLength);
	cout << "Longest Series Row:               " << longestSeriesRow << endl;
	cout << "Count of Columns which include 0: " << count << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

int countColumnsWithZero(int** a, int numRows, int numColumns, int j = 0, int i = 0, int count = 0, bool Haszero = false) {
	if (j < numColumns) {
		if (i < numRows) {
			if (a[i][j] == 0) {
				Haszero = true;
			}
			if (Haszero) count++;
			return countColumnsWithZero(a, numRows, numColumns, j, i + 1, count, Haszero = false);
		}

		return countColumnsWithZero(a, numRows, numColumns, j + 1, 0, count, Haszero = false);
	}

	return count;
}
void FindRowWithLongestSeries(int** arr, int rowCount, int colCount, int i, int j, int currentSeriesLength, int& rowWithLongestSeries, int& maxSeriesLength) {
	if (i == rowCount) {
		return;
	}
	if (j == colCount) {
		FindRowWithLongestSeries(arr, rowCount, colCount, i + 1, 1, 1, rowWithLongestSeries, maxSeriesLength);
		return;
	}
	if (arr[i][j] == arr[i][j - 1]) {
		currentSeriesLength++;
		if (currentSeriesLength > maxSeriesLength) {
			maxSeriesLength = currentSeriesLength;
			rowWithLongestSeries = i;
		}
	}
	else {
		currentSeriesLength = 1;
	}
	FindRowWithLongestSeries(arr, rowCount, colCount, i, j + 1, currentSeriesLength, rowWithLongestSeries, maxSeriesLength);
}