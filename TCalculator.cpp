#include "TCalculator.h"
#include "TStack.h"
#include <string>
#include <math.h>
using namespace std;

void TCalculator::setinfix(const char el) {
	infix += el;
}

char TCalculator::getinfix(const int n) {
	return infix[n];
}

char TCalculator::getpostfix(const int n) {
	return postfix[n];
}

bool TCalculator::check() {
	stc.clear();
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
			stc.push('(');
		if (infix[i] == ')')
		{
			if (stc.isempty())
				return false;
			else
				stc.pop();
		}
	}
	if (stc.isempty())
		return true;
	else
		return false;
}

int TCalculator::priority(const char& el) {
	if (el == '(')
		return 0;
	if (el == '+' || el == '-')
		return 1;
	if (el == '*' || el == '/')
		return 2;
	if (el == '^')
		return 3;
	if (el == ')')
		return 4;
}

void TCalculator::ToPostfix() {
	stc.clear();
	string tmp = '(' + infix + ')';
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == '(')
			stc.push(tmp[i]);
		if ((tmp[i] >= '0' && tmp[i] <= '9') || (tmp[i] == '.'))
			postfix += tmp[i];
		if (tmp[i] == ')')
		{
			char el = stc.pop();
			while (el != '(')
			{
				postfix += el;
				el = stc.pop();
			}
		}
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '^')
		{
			postfix += " ";
			while(priority(tmp[i])<=priority(stc.top()))
				postfix += stc.pop();
				stc.push(tmp[i]);
		}
	}
}

double TCalculator::calc() {
	STD.clear();
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			double res, op1, op2 = STD.pop();
			op1 = STD.pop();
			switch (postfix[i])
			{
			case '+':res = op1 + op2;
				break;
			case '-':res = op1 - op2;
				break;
			case '*':res = op1 * op2;
				break;
			case '/':res = op1 / op2;
				break;
			case '^':res = pow(op1, op2);
				break;
			}
			STD.push(res);
		}
		if ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.')
		{
			char *tmp;
			double res;
			res = strtod(&postfix[i], &tmp);
			int j = tmp - &postfix[i];
			i += j - 1;
			STD.push(res);
		}
	}
	return STD.pop();
}