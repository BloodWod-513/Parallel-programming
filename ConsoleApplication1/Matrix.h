#ifndef MATRIX_H
#define MATRIX_H

#include "Random.h"
#include "Vector.h"

template <class T>
class Vector;

template <class T>
class Matrix
{
private:
	int size;
	T** matrix;

public:
	Matrix(int size, bool zeroMatrix = false);
	~Matrix();
	Matrix(const Matrix& _matrix)
	{
		size = _matrix.size;
		matrix = new T *[size];

		for (int i = 0; i < size; i++)
			matrix[i] = new T[size];

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				matrix[i][j] = _matrix.matrix[i][j];
		}
	}

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

	Matrix operator*(Matrix& _matrix)
	{
		Matrix<T> resultMatrix(size, true);

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)
					resultMatrix.matrix[i][j] += matrix[i][k] * _matrix.GetValue(k, j);
			}
		}
		return resultMatrix;
	}

	Vector<T> operator*(Vector<T>& vector)
	{
		Vector<T> resultVector(vector.GetSize(), true);

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				T value = resultVector.GetValue(i) + matrix[i][j] * vector.GetValue(j);
				resultVector.SetValue(i, value);
			}
		}
		return resultVector;
	}

	void Print(const char* matrixName = "");
	void BubbleSort(bool ascending = true);
	void QuickSort();

	void SetValue(int rowIndex, int columnIndex, T value);
	T GetValue(int rowIndex, int columnIndex);
	int GetSize();
};

#endif // !MATRIX_H


