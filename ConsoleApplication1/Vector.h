#ifndef VECTOR_H
#define VECTOR_H

#include "Random.h"

template <class T>
class Vector
{
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

	void Print();
	T GetValue(int index);
	void SetValue(int index, T value);
};

#endif // !VECTOR_H


