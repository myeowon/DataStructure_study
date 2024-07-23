// 좋은 단어
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;
    int N;
    cin >> N;

    while (N--)
    {
        stack<char> S;
        bool possible = true;

        string line;
        cin >> line;

        if (line.length() % 2 != 0)
        {
            possible = false;
        }
        else
        {
            for (char c : line)
            {
                if (!S.empty() && S.top() == c)
                {
                    S.pop();
                }
                else
                {
                    S.push(c);
                }
            }
        }

        if (!S.empty())
            possible = false;

        if (possible)
            count++;
    }
    cout << count;
}