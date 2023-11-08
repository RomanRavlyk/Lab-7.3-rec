#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int countColumnsWithZero(int** a, int numRows, int numColumns, int column, int& count);
void FindRowWithLongestSeries(int** arr, int rowCount, int colCount, int& rowWithLongestSeries, int& maxSeriesLength);
void FindRowWithLongestSeriesRecursive(int** arr, int rowCount, int colCount, int i, int j, int currentSeriesLength, int& maxSeriesLength, int& rowWithLongestSeries);
void FindRowWithLongestSeries(int** arr, int rowCount, int colCount, int& rowWithLongestSeries, int& maxSeriesLength);
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
	// CreateRows(a, rowCount, colCount, Low, High, 0);
	InputRows(a, rowCount, colCount, 0);
	PrintRows(a, rowCount, colCount, 0);

	int count = 0;
	countColumnsWithZero(a, rowCount, colCount, 0, count);
	int longestSeriesRow = -1;
	int maxSeriesLength = 0;
	FindRowWithLongestSeries(a, rowCount, colCount, longestSeriesRow, maxSeriesLength);
	cout << "Longest Series Row:               " << longestSeriesRow << endl;
	cout << "Count of Columns which include 0: " << count << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}

int countColumnsWithZero(int** a, int numRows, int numColumns, int column, int& count) {
	if (column == numColumns) {
		return count;
	}

	bool hasZero = false;
	for (int i = 0; i < numRows; i++) {
		if (a[i][column] == 0) {
			hasZero = true;
			break;
		}
	}

	if (hasZero) {
		count++;
	}

	return countColumnsWithZero(a, numRows, numColumns, column + 1, count);
}

void FindRowWithLongestSeriesRecursive(int** arr, int rowCount, int colCount, int i, int j, int currentSeriesLength, int& maxSeriesLength, int& rowWithLongestSeries) {
    if (i == rowCount) {
        return;  // Всі рядки перевірено
    }

    if (j == colCount) {
        // Перевірка рядка завершена, переходимо до наступного рядка
        if (currentSeriesLength > maxSeriesLength) {
            maxSeriesLength = currentSeriesLength;
            rowWithLongestSeries = i;
        }
        FindRowWithLongestSeriesRecursive(arr, rowCount, colCount, i + 1, 1, 1, maxSeriesLength, rowWithLongestSeries);
    } else {
        if (arr[i][j] == arr[i][j - 1]) {
            // Знайдено однакові елементи
            currentSeriesLength++;
        } else {
            // Послідовність порушена
            currentSeriesLength = 1;
        }
        FindRowWithLongestSeriesRecursive(arr, rowCount, colCount, i, j + 1, currentSeriesLength, maxSeriesLength, rowWithLongestSeries);
    }
}

void FindRowWithLongestSeries(int** arr, int rowCount, int colCount, int& rowWithLongestSeries, int& maxSeriesLength) {
	FindRowWithLongestSeriesRecursive(arr, rowCount, colCount, 0, 1, 1, maxSeriesLength, rowWithLongestSeries);
}