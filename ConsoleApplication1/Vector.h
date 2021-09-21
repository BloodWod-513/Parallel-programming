#ifndef VECTOR_H
#define VECTOR_H

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
};

#endif // !VECTOR_H


