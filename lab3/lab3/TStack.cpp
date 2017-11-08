#include "TStack.h"

template <class T>
TStack<T>::TStack(int _size = 200) {
	if (_size <= 0)
		throw _size;
	arr = new T[_size];
	MaxSize = _size;
	size = 0;
}

template <class T>
TStack<T>::~TStack() {
	delete[] arr;
}

template <class T>
TStack<T>::TStack(const TStack& ts) {
	size = ts.size;
	MaxSize = ts.MaxSize;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = ts.arr[i];
}

template <class T>
TStack<T> &TStack:: operator=(const TStack& ts) {
	if (this != &ts)
	{
		if (MaxSize != ts.MaxSize)
		{
			delete[] arr;
			MaxSize = ts.MaxSize;
			arr = new T[MaxSize];
		}
		size = ts.size;
		for (int i = 0; i < size; i++)
			arr[i] = ts.arr[i];
	}
	return *this;
}

template <class T>
int TStack<T>::isfull() {
	if (size == MaxSize)
		return 1;
	else
		return 0;
}

template <class T>
int TStack<T>::isempty() {
	if (size = 0)
		return 1;
	else
		return 0;
}

template <class T>
T TStack<T>::top() {
	if (isempty())
		throw - 1;
	return arr[size - 1];
}

template <class T>
T TStack<T>::pop() {
	if (isempty())
		throw - 1;
	size--;
	return arr[size];
}

template <class T>
void TStack<T>::push(const T& el) {
	if (isfull())
		throw - 1;
	arr[size] = el;
	size++;
}

template <class T>
void TStack<T>::clear() {
	size = 0;
}