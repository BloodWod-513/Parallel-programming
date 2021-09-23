#include <iostream>
#include "Matrix.h"
#include "Vector.h"
using namespace std;

int main()
{
	int size;
	cin >> size;

	Matrix <int> matrix(size);
	matrix.Print("matrix one");
	matrix.BubbleSort();
	matrix.Print();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			matrix.SetValue(i, j, 2);
	}
	Matrix <int> matrixTest(size);
	matrixTest = matrix;
	matrixTest.Print("matrix test");

	Matrix <int> test = matrix;
	test.Print("test");
	matrix = matrixTest * test;
	matrix.Print("matrix test * test");

	Vector <int> vector(size);
	for (int i = 0; i < size; i++)
	{
		vector.SetValue(i, 2);
	}
	vector.Print();

	vector = matrix * vector;
	vector.Print();
	vector = vector * test;
	vector.Print();

	Vector <int> vectorSort(size);
	vectorSort.Print();
	vectorSort.BubbleSort();
	vectorSort.Print();
    std::cout << "Hello World!\n";
}
