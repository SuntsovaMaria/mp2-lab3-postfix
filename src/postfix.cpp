#include "postfix.h"
#include "stack.h"
#include <exception>

using namespace std;
const string numbers = "0123456789";
const string operation = "-+/*";

Expression::Expression(string inf) {
	
		infix = inf;
    	priority = { {'(',0},{'+',1},{'-',1},{'/',2},{'*',2}};
		postfix = "";
		toPostfix();
	
}
void Expression::Parse() {
	for (char c : infix) {
		lexems.push_back(c);
	}

}

void Expression::toPostfix() {
	
	Parse();
	TStack<char> st;
	char stackItem;
	for (char item : lexems) {
		switch (item) {
		case '(':
			st.push(item);
			break;
		case ')':
			if (!st.isEmpty()) {
				stackItem = st.top();
				st.pop();
			}
			while (stackItem != '(') {
				postfix += stackItem;
				stackItem = st.top();
				st.pop();
			}
			break;
		case '+':case '-':case '*':case '/':
			while (!st.isEmpty()) {
				stackItem = st.top();
				if (priority[item] <= priority[stackItem]) {
					postfix += stackItem;
					st.pop();
				}
				else {
					break;
				}
			}
			st.push(item);
			break;
		default:
			operands.insert({ item,item - '0' });
			postfix += item;
		}
	}
	while (!st.isEmpty()) {
		stackItem = st.top();
		st.pop();
		postfix += stackItem;
	}
}

double Expression::calc() {
	if (!iscorrect())
		throw invalid_argument("is not correct");
	TStack <double> st;
	double leftop, rightop;
	for (char lexem : postfix)
	{
		switch (lexem) {
			{case '+':
				rightop = st.top();
				st.pop();
				leftop = st.top();
				st.pop();
				st.push(rightop + leftop);
				break;
			}
			{case '-':
				rightop = st.top();
				st.pop();
				leftop = st.top();
				st.pop();
				st.push(leftop - rightop);
				break;
				
			}
			{case '*':
				rightop = st.top();
				st.pop();
				leftop = st.top();
				st.pop();
				st.push(rightop * leftop);
				break;
			}
			{case '/':
				rightop = st.top();
				st.pop();
				leftop = st.top();
				if (rightop == 0) 
					throw("div 0");
				st.pop();
				st.push(leftop/rightop);
				break;
			}
		default:
			st.push(operands[lexem]);

		}
	}
	double res = st.top();
	st.pop();
	return res;
}

bool Expression::iscorrect() {
	bool res = true;
	bool fl1 = true;
	bool fl2 = true;
	TStack <char> br;
	for (char e : infix) {
		if (e == '(')
			br.push(e);
		else if (e == ')') {
			if (br.isEmpty()) {
				res = false;
				fl1 = false;
				break;
			}
			else {
				br.pop();
			}
		}
	}
	if (br.isEmpty() == false) {
		res = false;
		fl1 = false;
	}
	
	if (numbers.find(infix[0]) == -1 && infix[0] != '(') {
		res = false;
		cout << "first symbol is not correct" << endl;
	}


	for (int i = 0; i < infix.length() - 1; i++) {
		if ((operation.find(infix[i]) != -1) && ((numbers.find(infix[i + 1]) != -1) || (infix[i + 1] == '('))) {
			continue;
		}
		else if ((numbers.find(infix[i]) != -1) && ((operation.find(infix[i + 1]) != -1) || (infix[i + 1] == ')'))) {
			continue;
		}
		else if ((infix[i] == '(') && ((numbers.find(infix[i + 1]) != -1) || (infix[i + 1] == '('))) {
			continue;
		}
		else if ((infix[i] == ')') && ((operation.find(infix[i + 1]) != -1) || (infix[i + 1] == ')'))) {
			continue;
		}
		else {
			res = false;
			fl2 = false;
			
		}
	}
	if (!fl1) {
		cout << "brackets are not correct" << endl;
	}
	if (!fl2) {
		cout << "symbols are not correct" << endl;
	}

	return res;
}


