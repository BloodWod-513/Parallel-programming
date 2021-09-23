#ifndef VECTOR_H
#define VECTOR_H

#include "Random.h"
#include "Matrix.h"

template <class T>
class Matrix;

template <class T>
class Vector
{
	//Matrix<T>* matrix;
private:
	int size;
	T* vector;

public:
	Vector(int size, bool zeroVector = false);
	~Vector();
	Vector(const Vector& _vector)
	{
		size = _vector.size;
		vector = new T[size];
		for (int i = 0; i < size; i++)
			vector[i] = _vector.vector[i];
	}

	Vector operator=(const Vector& _vector)
	{
		delete[] vector;
		size = _vector.size;
		vector = new T[size];
		for (int i = 0; i < size; i++)
			vector[i] = _vector.vector[i];
		return *this;
	}

	Vector operator*(Matrix<T>& matrix)
	{
		Vector<T> resultVector(size, true);

		for (int i = 0; i < matrix.GetSize(); i++)
		{
			for (int j = 0; j < matrix.GetSize(); j++)
			{
				T value = resultVector.GetValue(i) + matrix.GetValue(i, j) * vector[j];
				resultVector.SetValue(i, value);
			}
		}
		return resultVector;
	}

	void Print();
	void BubbleSort(bool ascending = true);

	void SetValue(int index, T value);
	T GetValue(int index);
	int GetSize();
};
template <typename T>
Vector<T> operator*(Matrix<T>& matrix, Vector<T>& vector)
{
	Vector<T> resultVector(vector.GetSize(), true);

	for (int i = 0; i < matrix.GetSize(); i++)
	{
		for (int j = 0; j < matrix.GetSize(); j++)
		{
			T value = resultVector.GetValue(i) + matrix.GetValue(i, j) * vector.GetValue(j);
			resultVector.SetValue(i, value);
		}
	}
	return resultVector;
}
#endif // !VECTOR_H


