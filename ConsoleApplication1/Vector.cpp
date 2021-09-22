#include "Vector.h"
#include <iostream>

template class Vector<int>;
template class Vector<float>;
template class Vector<double>;

template <typename T>
Vector<T>::Vector(int size, bool zeroVector)
{
	this->size = size;
	vector = new T[size];
	for (int i = 0; i < size; i++)
		vector[i] = zerovector ? 0 : GetRand(0.f, 100.f);
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] vector;
}

template <typename T>
T Vector<T>::GetValue(int index)
{
	if (index < 0 || index >= size)
		throw std::invalid_argument("received wrong index");
	return vector[index];
}

template <typename T>
void Vector<T>::SetValue(int index, T value)
{
	if (index < 0 || index >= size)
		throw std::invalid_argument("received wrong index");
	vector[index] = value;
}

template <typename T>
void Vector<T>::Print()
{
	std::cout << "Vector: ";
	for (int i = 0; i < size; i++)
		std::cout << vector[i] << ' ';
	std::cout << std::endl;
}
