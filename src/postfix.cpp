#include "postfix.h"
#include "stack.h"
using namespace std;
const string numbers = "0123456789";
const string operation = "-+/*";

Expression::Expression(string inf) {
	
		infix = inf;
		priority = { {'(',0},{'+',1},{'-',1},{'/',2},{'*',2} };
		toPostfix();
	
}
void Expression::Parse() {
	for (char c : infix) {
		lexems.push_back(c);
	}

}

void Expression::toPostfix() {
	minus();
	if (!iscorrect())
		throw ("is not correct");
	
		Parse();
		TStack<char> st;
		char stackItem;
		for (char item : lexems) {
			switch (item) {
			case '(':
				st.push(item);
				break;
			case ')':
				stackItem = st.top();
				st.pop();
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
						st.pop();
						postfix += stackItem;
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
		throw ("is not correct");
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
	TStack <char> bracers;
	for (char e : infix) {
		if (e == '(')
			bracers.push(e);
		else if (e == ')') {
			if (bracers.isEmpty()) {
				res = false;
				cout << "bracers is not correct" << endl;
				break;
			}
			else {
				bracers.pop();
			}
		}
	}
	if (bracers.isEmpty() == false) {
		res = false;
		cout << "bracers is not correct" << endl;
		
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
			cout << "expression in not correct" << endl;
		}
	}

	return res;
}

void Expression::minus() {
	string result = "";
    int i = 0;
	while (i < infix.length()) {
		if (infix[i] == '-' && (i == 0 || operation.find(infix[i - 1]) != -1 || infix[i - 1] == '(')) {
			result += "(0-";
			++i;

			if (infix[i] != '(') {
				while (i < infix.length() && numbers.find(infix[i]) !=-1) {
					result += infix[i];
					++i;
				}
				result += ')';
			}
			else {
				int j = i + 1;
				int bracers = 1;
				result += infix[i];
				while ((j < infix.length())&&bracers!=0) {
					result += infix[j];
					if (infix[j] == ')')
						bracers -= 1;
					if (infix[j] == '(')
						bracers += 1;

					if (bracers == 0) {
						result += ')';
						
					}
					j++;
				}

				i = j;
			}

		}
		else {
			result += infix[i];
			++i;
		}
	}
	infix = result;
}
