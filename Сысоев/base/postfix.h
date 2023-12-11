#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#pragma once
#include<iostream>
#include <vector>
#include <map>
#include<string>
#include "stack.h"

using namespace std;

class Expression {
	string infix;
	string postfix;
	vector <char> lexems;
	map<char, int> priority;
	map<char, double> operands;
	void Parse();
	void toPostfix();
public:
	Expression(string inf);
	string GetInfix()const {
		return infix;
	}
	string GetPostfix()const {
		return postfix;
	}
	vector<char> GetOperands() const;
	double calc(const map<char, double>& val);
	bool iscorrect(string inf);
};

#endif
