#include "dataStructures.cpp"

int ValidBrackets(string brackets)
{
    int count = 0;
    stack<char> stack;
    for (int i = 0; i < brackets.size(); i++)
    {
        if (brackets[i] == '(')
        {
            stack.push('(');
        }
        else if (brackets[i] == ')')
        {
            if (!stack.isEmpty())
            {
                stack.pop();
                count += 2;
            }
        }
    }
    return count;
}

int main()
{
    string test = "()())()))())(())";
    int count = ValidBrackets(test);
    cout << count;
}