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

	cout.precision(8);

	Matrix <int> matrix(size);
	matrix.Print("matrix");
	matrix.QuickSort();
	clock_t timer = clock();
	cout << "Estimated time of matrix quick sort: " << fixed << static_cast<double>(clock() - timer) / CLOCKS_PER_SEC << " sec" << endl;
	matrix.Print();

	Matrix <int> matrixTest(size);
	matrixTest.Print("matrixTest");
	timer = clock();
	matrixTest.BubbleSort();
	cout << "Estimated time of matrix bubble sort: " << fixed << static_cast<double>(clock() - timer) / CLOCKS_PER_SEC << " sec" << endl;
	matrixTest.Print();

	//matrix.BubbleSort(); Estimated time of multiplication by vector:
	/*for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			matrix.SetValue(i, j, 2);
	}*/
	/*Matrix <int> matrixTest(size);
	matrixTest = matrix;
	matrixTest.Print("matrix test");*/

	Matrix <int> test = matrix;
	test.Print("test");
	timer = clock();
	matrix = matrix * test;
	cout << "Estimated time multiplying on matrix: " << fixed << static_cast<double>(clock() - timer) / CLOCKS_PER_SEC << " sec" << endl;
	matrix.Print("matrix * test");

	Vector <int> vector(size);
	//for (int i = 0; i < size; i++)
	//{
	//	vector.SetValue(i, 2);
	//}
	vector.Print();

	timer = clock();
	vector = matrix * vector;
	cout << "Estimated time multiplying on vector: " << fixed << static_cast<double>(clock() - timer) / CLOCKS_PER_SEC << " sec" << endl;
	vector.Print();

	timer = clock();
	vector.BubbleSort();
	cout << "Estimated time of vector bubble sort: " << fixed << static_cast<double>(clock() - timer) / CLOCKS_PER_SEC << " sec" << endl;
	vector.Print();

	/*vector = vector * test;
	vector.Print();*/

	Vector <int> vectorSort(size);
	vectorSort.Print();
	//vectorSort.BubbleSort();
	timer = clock();
	vectorSort.QuickSort(0, size - 1, true);
	cout << "Estimated time of vector quick sort: " << fixed << static_cast<double>(clock() - timer) / CLOCKS_PER_SEC << " sec" << endl;
	vectorSort.Print();

	int number;
	cout << endl;
	cout << "Number: ";
	cin >> number;
	cout << endl;
	timer = clock();
	double result = RectangleMethod(number);
	cout << "Estimated time of rectangle method: " << fixed << static_cast<double>(clock() - timer) / CLOCKS_PER_SEC << " sec" << endl;
	cout << "Result rectangle: " << result << endl << endl;
	timer = clock();
	result = TrapezoidMethod(number);
	cout << "Estimated time of vector method: " << fixed << static_cast<double>(clock() - timer) / CLOCKS_PER_SEC << " sec" << endl;
	cout << "Result trapezoid: " << result << endl << endl;
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