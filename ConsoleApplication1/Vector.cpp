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
		vector[i] = zeroVector ? 0 : GetRand(0.f, 100.f);
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] vector;
}

template<typename T>
int Vector<T>::GetSize()
{
	return size;
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
	std::cout << std::endl << std::endl;
}

template <typename T>
void Vector<T>::BubbleSort(bool ascending)
{
	T temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (ascending)
			{
				if (vector[i] <= vector[j])
					continue;
			}
			else
			{
				if (vector[i] >= vector[j])
					continue;
			}

			temp = vector[i];
			vector[i] = vector[j];
			vector[j] = temp;
		}
	}
}
