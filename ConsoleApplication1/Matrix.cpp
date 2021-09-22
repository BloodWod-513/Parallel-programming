#include "Matrix.h"
#include <iostream>

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;

template <typename T>
Matrix<T>::Matrix(int size, bool zeroMatrix)
{
	this->size = size;
	matrix = new T * [size];

	for (int i = 0; i < size; i++)
		matrix[i] = new T[size];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			matrix[i][j] = zeroMatrix ? 0 : GetRand(0.f, 100.f);
	}
}

template <typename T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < size; ++i) 
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

template<typename T>
int Matrix<T>::GetSize()
{
	return size;
}

template <typename T>
T Matrix<T>::GetValue(int rowIndex, int columnIndex)
{
	if (rowIndex < 0 || columnIndex < 0 || columnIndex >= size || rowIndex >= size)
		throw std::invalid_argument("received wrong index");
	return matrix[rowIndex][columnIndex];
}

template <typename T>
void Matrix<T>::SetValue(int rowIndex, int columnIndex, T value)
{
	if (rowIndex < 0 || columnIndex < 0 || columnIndex >= size || rowIndex >= size)
		throw std::invalid_argument("received wrong index");
	matrix[rowIndex][columnIndex] = value;
}

template <typename T>
void Matrix<T>::Print(const char* matrixName)
{
	std::cout << "Matrix: " << matrixName << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			std::cout << matrix[i][j] << ' ';
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
