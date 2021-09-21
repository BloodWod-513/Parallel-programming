#ifndef MATRIX_H
#define MATRIX_H

#include "Random.h"

template <class T>
class Matrix
{
private:
	int size;
	T** matrix;

public:
	Matrix(int size);
	~Matrix();

	void Print();
};

#endif // !MATRIX_H

