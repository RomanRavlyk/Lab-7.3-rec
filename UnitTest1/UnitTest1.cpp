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

            int rowCount = 3, colCount = 3;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];


            CreateRows(a, rowCount, colCount, -7, 7, 0);

            int count = 0;
            countColumnsWithZero(a, rowCount, colCount, 0, count);
            int longestSeriesRow = -1;
            int maxSeriesLength = 0;
            FindRowWithLongestSeries(a, rowCount, colCount, 0, 0, 1, longestSeriesRow, maxSeriesLength);


            Assert::AreEqual(0, count);
            Assert::AreEqual(2, longestSeriesRow);
        }


    };
}