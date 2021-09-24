#include "Matrix.h"
#include <iostream>

template class Matrix<int>;
template class Matrix<float>;
template class Matrix<double>;

template <typename T>
Matrix<T>::Matrix(int size, bool zeroMatrix)
{
	this->size = size;
	matrix = new T *[size];

	for (int i = 0; i < size; i++)
		matrix[i] = new T[size];

	//matrix = malloc(size);
	//*matrix = malloc(size * size * *matrix);
	//for (int i = 0; i < size; ++i)
	//	matrix[i] = matrix[0] + i * size;

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

template <typename T>
void Matrix<T>::BubbleSort(bool ascending)
{
	T temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int h = 0; h < size; h++)
			{
				for (int k = 0; k < size; k++)
				{
					if (ascending)
					{
						if (matrix[i][j] >= matrix[h][k])
							continue;
					}
					else
					{
						if (matrix[i][j] <= matrix[h][k])
							continue;
					}
					temp = matrix[i][j];
					matrix[i][j] = matrix[h][k];
					matrix[h][k] = temp;
				}
			}
		}
	}
}

int compare_ints(const void* a, const void* b)
{
	int arg1 = *(const int*)a;
	int arg2 = *(const int*)b;

	if (arg1 < arg2) return -1;
	if (arg1 > arg2) return 1;
	return 0;

	return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
	// return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
};

//TODO: make it smarter
template <typename T>
void Matrix<T>::QuickSort()
{
	T* mat = new T[size * size];
	int x = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			mat[x] = matrix[i][j];
			x++;
		}
	}
	std::qsort(mat, size * size, sizeof *mat, compare_ints);
	x = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			matrix[i][j] = mat[x];
			x++;
		}
	}
}
