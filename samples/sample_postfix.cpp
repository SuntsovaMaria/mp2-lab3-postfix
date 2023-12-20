#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;


int main() {
    string inputExpression;
    bool isExpressionCorrect = false;

    while (!isExpressionCorrect) {
        cout << "Enter expression: ";
        cin >> inputExpression;

        Expression expr(inputExpression);
        isExpressionCorrect = expr.iscorrect();

        if (!isExpressionCorrect) {
            cout << "Expression is not correct! Please, try again." << endl;
        }
    }

    cout << "expression '" << inputExpression << "' is correct" << std::endl;
    Expression expr(inputExpression);
    cout << "infix:" << expr.GetInfix() << endl;
    cout << "postfix:" << expr.GetPostfix() << endl;
    cout << "result of calculation:" << expr.calc() << endl;
    return 0;
}
