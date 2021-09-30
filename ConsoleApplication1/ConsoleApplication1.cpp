#define _USE_MATH_DEFINES

#include <iostream>
#include "Matrix.h"
#include "Vector.h"
#include <math.h>

using namespace std;

double RectangleMethod(int number);
double TrapezoidMethod(int number);
double func(double x);

int main()
{
	int size = 0;
	cin >> size;

	Matrix <int> matrix(size);
	matrix.Print("matrix one");
	matrix.QuickSort();
	//matrix.BubbleSort();
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
	//vectorSort.BubbleSort();
	vectorSort.QuickSort(0, size - 1, true);
	vectorSort.Print();
    cout << "Hello World!\n";

	int number;
	cout << endl;
	cout << "Number: ";
	cin >> number;
	double result = RectangleMethod(number);
	cout << "Result rectangle: " << result << endl;
	result = TrapezoidMethod(number);
	cout << "Result trapezoid: " << result << endl;
}

double RectangleMethod(int number)
{
	double start = 0, end = M_PI, result = 0, x = 0, step = end / number;
	for (int i = 0; i < number; i++)
	{
		x = step / 2 + step * i;
		result += func(x);
	}
	return result * step;
}

double TrapezoidMethod(int number)
{
	double start = 0, end = M_PI, result = 0, x = 0, step = end / number;
	for (int i = 0; i < number; i++)
	{
		x = step * i;
		result += func(x);
		x = step * (i + 1);
		result += func(x);
	}
	return step / 2 * result;
}

double func(double x)
{
	return (8 * pow(x, 2) + 16 * x + 17) * cos(4 * x);
}