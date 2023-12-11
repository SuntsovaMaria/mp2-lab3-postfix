#include "postfix.h"
#include "stack.h"

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
	Parse();
	TStack<char> st;
	char stackItem;
	for (char item : lexems) {
		switch (item) {
		case '(':
		{
			st.push(item);
			break;
		}
		case ')': {
			stackItem = st.top();
			st.pop();
			while (stackItem != '(') {
				postfix += stackItem;
				stackItem = st.top();
				st.pop();
			}
			break;
		}
		case'+':case'-':case'*':case'/': {
			while (!st.isEmpty()) {
				stackItem = st.top();
				if (priority[item] <= priority[stackItem]) {
					st.pop();
					postfix += stackItem;
				}
				else
					break;
			}

		}
		default: {
			operands.insert({ item,0.0 });
			postfix += item;
		}

		}
		while (!st.isEmpty()) {
			stackItem = st.top();
			st.pop();
			postfix += stackItem;
		}
	}
}
double Expression::calc(const map<char, double>& values) {
	for (auto& val : values)
	{
		try {
			operands.at(val.first) = val.second;
		}
		catch(out_of_range &e){}
	}
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
				st.push(rightop - leftop);
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
				if (leftop == 0) throw("div 0");
				st.pop();
				st.push(rightop / leftop);
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
bool Expression::iscorrect(string inf) {
	bool res = true;
	for (char e : inf) {
		int leftb = 0;
		int rightb = 0;
		if (e == '(')
			leftb++;
		if (e == ')')
			rightb++;
		if (leftb != rightb)
			res = false;
		cout << "bracers is not correct" << endl;
	}
	
	
}