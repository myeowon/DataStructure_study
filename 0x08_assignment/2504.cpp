// °ýÈ£ÀÇ °ª
#include <bits/stdc++.h>
using namespace std;

int calculate(stack<char> S, int start)
{
    while (!S.empty())
    {
        if (S.top() == '(')
            start *= 2;
        else if (S.top() == '[')
            start *= 3;
        S.pop();
    }
    return start;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> S;

    string str;
    cin >> str;

    int result = 0;
    bool possible = true;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];

        if (c == '(' || c == '[')
        {
            S.push(c);
        }
        else if (c == ')')
        {
            if (!S.empty() && S.top() == '(')
            {
                S.pop();
                if (str[i - 1] == '(')
                    result += calculate(S, 2);
            }
            else
            {
                possible = false;
            }
        }
        else if (c == ']')
        {
            if (!S.empty() && S.top() == '[')
            {
                S.pop();
                if (str[i - 1] == '[')
                    result += calculate(S, 3);
            }
            else
            {
                possible = false;
            }
        }
    }
    if (!S.empty())
        possible = false;
    if (!possible)
        result = 0;
    cout << result;
}