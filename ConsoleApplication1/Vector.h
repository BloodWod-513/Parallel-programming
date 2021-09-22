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
	Vector(int size);
	~Vector();

	void Print();
	T GetValue(int index);
	void SetValue(int index, T value);
};

#endif // !VECTOR_H


