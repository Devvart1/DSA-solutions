#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOperator(char c)
{
    if (c == '*' || c == '+' || c == '-' || c == '/')
        return true;
    return false;
}

int performOperation(int a, int b, char operation)
{
    if (operation == '*') return a * b;
    else if (operation == '+') return a + b;
    else if (operation == '-') return a - b;
    else if (operation == '/') return a / b;
    else return 0;
}

int evaluate(string expressions)
{
    stack<int> values;
    stack<char> operators;

    for (int i = 0; i < expressions.length(); i++)
    {
        if (expressions[i] == ' ')
            continue;

        else if (isOperator(expressions[i]))
        {
            while (!operators.empty() && operators.top() != '(' &&
                    performOperation(values.top(), values.top(), operators.top()) <=
                    performOperation(values.top(), (int)(expressions[i] - '0'), expressions[i]))
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(performOperation(val1, val2, op));
            }
            operators.push(expressions[i]);
        }

        else if (expressions[i] == '(')
            operators.push(expressions[i]);

        else if (expressions[i] == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                int val2 = values.top();
                values.pop();
                int val1 = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(performOperation(val1, val2, op));
            }
            operators.pop();
        }

        else
        {
            int val = 0;
            while (i < expressions.length() && isdigit(expressions[i]))
            {
                val = (val * 10) + (int)(expressions[i] - '0');
                i++;
            }
            i--;
            values.push(val);
        }
    }

    while (!operators.empty())
    {
        int val2 = values.top();
        values.pop();
        int val1 = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(performOperation(val1, val2, op));
    }

    return values.top();
}

int main()
{
    string expression;
    cout << "Enter the expression: ";
    getline(cin, expression);
    int result = evaluate(expression);
    cout << "Result: " << result << endl;
    return 0;
}



