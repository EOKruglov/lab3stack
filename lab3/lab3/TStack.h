#pragma once
template <class T>
class TStack {
	int size, MaxSize;
	T* arr;
public:
	TStack(int _size = 200);
	~TStack();
	TStack(const TStack& ts);
	TStack& operator=(const TStack& ts);
	int isfull();
	int isempty();
	T top();
	T pop();
	void push(const T& el);
	void clear();
};
