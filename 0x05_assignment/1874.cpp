// 스택 수열
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, t;
    stack<int> S;
    queue<char> Q;
    bool possible = true;
    int idx = 1;

    cin >> N;
    while (N--)
    {
        cin >> t;

        if (t >= idx)
        {
            int loop = t - idx + 1;

            for (int i = 0; i < loop; i++)
            {
                S.push(idx);
                idx++;
                Q.push('+');
            }
            S.pop();
            Q.push('-');
        }
        else
        {
            if (S.top() != t)
            {
                possible = false;
            }
            else
            {
                S.pop();
                Q.push('-');
            }
        }
    }
    if (!possible)
    {
        cout << "NO";
    }
    else
    {
        while (!Q.empty())
        {
            cout << Q.front() << "\n";
            Q.pop();
        }
    }
}