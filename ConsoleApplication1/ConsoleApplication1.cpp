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

	Matrix <int> matrixTest(size);
	matrixTest = matrix;
	matrixTest.Print("matrix test");

	Matrix <int> test = matrix;
	test.Print("test");
	matrix = matrixTest * test;
	matrix.Print("matrix test * test");

	Vector <int> vector(size);
	vector.Print();

	Vector <int> testVector(size);
	testVector.Print();
	testVector = vector;
	testVector.Print();
    std::cout << "Hello World!\n";
}