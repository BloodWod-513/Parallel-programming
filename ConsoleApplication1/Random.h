#ifndef RANDOM_H
#define RANDOM_H
#include <iostream>
#include <random>

template <class T>
using uniform_distribution =
typename std::conditional<
	std::is_floating_point<T>::value,
	std::uniform_real_distribution<T>,
	typename std::conditional<
	std::is_integral<T>::value,
	std::uniform_int_distribution<T>,
	void
	>::type
>::type;

template <class T>
T GetRand(T begin, T end) 
{
	static thread_local std::mt19937_64 mt(std::random_device{}());
	uniform_distribution<T> distribution(begin, end);

	return int(distribution(mt) * 100) / 100.0;
}

#endif // !RANDOM_H
