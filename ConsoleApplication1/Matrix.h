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

	void Print(const char* matrixName = "");
	void SetValue(int rowIndex, int columnIndex, T value);
	T GetValue(int rowIndex, int columnIndex);
};

#endif // !MATRIX_H


