#include "pch.h"
#include "CppUnitTest.h"
#include "../пр7.2іт/7.2іт.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72іт
{
	TEST_CLASS(UnitTest72іт)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            int matrix[n][n] = {
                {19, 53, 7},
                {55, 38, 47},
                {42, 31, 38}
            };

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = matrix[i][j];
                }
            }

            SwapMinElementsToDiagonal(a, n);

            int expectedMatrix[n][n] = {
                {19, 53, 7},
                {55, 38, 47},
                {31, 42, 38}
            };

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    Assert::AreEqual(expectedMatrix[i][j], a[i][j]);
                }
            }

            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
        }
    };
}


