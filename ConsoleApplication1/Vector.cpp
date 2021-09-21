#include "Vector.h"
#include <iostream>
#include "Random.h"

template class Vector<int>;
template class Vector<float>;
template class Vector<double>;

template<typename T>
Vector<T>::Vector(int size)
{
	this->size = size;
	vector = new T[size];
	for (int i = 0; i < size; i++)
		vector[i] = GetRand(0.f, 100.f);
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] vector;
}

template<typename T>
void Vector<T>::Print()
{
	std::cout << "Vector: ";
	for (int i = 0; i < size; i++)
		std::cout << vector[i] << ' ';
	std::cout << std::endl;
}
