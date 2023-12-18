#include <iostream>
#include <string>
#include "postfix.h"

using namespace std;

int main()
{
    string expression;
    bool inputValid = false;
    cout << "Enter expression: " << endl;
    cin >> expression;
    while (!inputValid) {
        Expression expr(expression);
        if (expr.iscorrect()) {
            inputValid = true;
            cout << "Infix: " << expr.GetInfix() << endl;
            cout << "Postfix: " << expr.GetPostfix() << endl;
            cout << "Result: " << expr.calc() << endl;

        }
        else {
            
            cout << "Error. Please try again" << endl;
        }
    }

}
