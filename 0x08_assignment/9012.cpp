// °ýÈ£
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while (N--)
    {
        stack<char> S;
        bool possible = true;
        string str;
        cin >> str;
        if (str.length() % 2 != 0)
        {
            possible = false;
        }
        else
        {
            for (char c : str)
            {
                if (c == '(')
                {
                    S.push(c);
                }
                else if (c == ')')
                {
                    if (!S.empty() && S.top() == '(')
                    {
                        S.pop();
                    }
                    else
                    {
                        possible = false;
                    }
                }
            }
            if (!S.empty())
                possible = false;
        }
        if (possible)
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
}