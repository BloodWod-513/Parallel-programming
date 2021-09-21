#include "Matrix.h"
#include <iostream>
#include <random>

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;

template <typename T>
Matrix<T>::Matrix(int size)
{
	this->size = size;
	matrix = new T* [size];

	for (int i = 0; i < size; i++)
		matrix[i] = new T[size];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			matrix[i][j] = GetRand(0.f, 100.f);
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

template <typename T>
void Matrix<T>::Print()
{
	std::cout << "Matrix: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			std::cout << matrix[i][j] << ' ';
		std::cout << std::endl;
	}
}