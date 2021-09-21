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
	Matrix(const Matrix& _matrix)
	{
		size = _matrix.size;
		matrix = new T * [size];

		for (int i = 0; i < size; i++)
			matrix[i] = new T[size];

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				matrix[i][j] = _matrix.matrix[i][j];
		}
	}
	~Matrix();
	Matrix operator=(const Matrix& _matrix)
	{
		for (int i = 0; i < size; ++i)
		{
			delete[] matrix[i];
		}
		delete[] matrix;

		size = _matrix.size;
		matrix = new T *[size];

		for (int i = 0; i < size; i++)
			matrix[i] = new T[size];

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				matrix[i][j] =_matrix.matrix[i][j];
		}
		return *this;
	}

	void Print(const char* matrixName = "");
	void SetValue(int rowIndex, int columnIndex, T value);
	T GetValue(int rowIndex, int columnIndex);
};

#endif // !MATRIX_H


