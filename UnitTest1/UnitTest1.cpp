#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.3 rec/Lab 7.3 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            // Оголошуємо параметри для тесту
            int rowCount = 3, colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            // Ініціалізуємо масив a якщо необхідно
            CreateRows(a, rowCount, colCount, -7, 7, 0);

            int count = 0;
            countColumnsWithZero(a, rowCount, colCount, 0, count);
            int longestSeriesRow = -1;
            int maxSeriesLength = 0;
            FindRowWithLongestSeries(a, rowCount, colCount, longestSeriesRow, maxSeriesLength);

            // Перевіряємо результати тесту
            Assert::AreEqual(1, count);
            Assert::AreEqual(0, longestSeriesRow);
        }

        // Додавання інших тестів

    };
}