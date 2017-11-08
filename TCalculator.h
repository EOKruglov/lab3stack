#pragma once
#include "TStack.h"
#include <string>
using namespace std;

class TCalculator {
	string infix, postfix;
	TStack<char> stc;
	TStack<double> STD;
public:
	void setinfix(const char el);
	char getinfix(const int n);
	char getpostfix(const int n);
	bool check();
	int priority(const char& el);
	void ToPostfix();
	double calc();
};
