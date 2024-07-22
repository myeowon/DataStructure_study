// ±ÕÇüÀâÈù ¼¼»ó
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true)
    {
        bool balance = true;
        stack<char> S;
        string line;
        getline(cin, line);

        if (line == ".")
            break;

        for (char c : line)
        {
            // ¿©´Â °ýÈ£
            if (c == '(' || c == '[')
                S.push(c);
            // ´Ý´Â °ýÈ£
            else if (c == ')')
            {
                if (!S.empty() && S.top() == '(')
                    S.pop();
                else
                    balance = false;
            }
            else if (c == ']')
            {
                if (!S.empty() && S.top() == '[')
                    S.pop();
                else
                    balance = false;
            }
        }

        if (!S.empty())
            balance = false;

        if (balance)
            cout << "yes";
        else
            cout << "no";
        cout << '\n';
    }
}