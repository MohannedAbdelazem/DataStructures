#include "dataStructures.cpp"

int checkPriority(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '^')
    {
        return 3;
    }
    return 0;
}

string InfixToPostfix(string infix)
{
    stack<char> stack;
    string postfix;
    for (int i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            while (!stack.isEmpty())
            {
                if (checkPriority(infix[i]) <= checkPriority(stack.Top()))
                {
                    postfix += stack.pop();
                }
                else
                {
                    break;
                }
            }
            stack.push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            stack.push('(');
        }
        else if (infix[i] == ')')
        {
            while (stack.Top() != '(')
            {
                postfix += stack.pop();
            }
            stack.pop();
        }
        else
        {
            postfix += infix[i];
        }
    }
    while (!stack.isEmpty())
    {
        postfix += stack.pop();
    }

    return postfix;
}

int main()
{
    string infix = "A + B * C + D";
    string postfix;
    postfix = InfixToPostfix(infix);
    cout << postfix;

    return 0;
}