// 스택 - 스택 수열
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    queue<char> result;
    bool possible = true;

    int n, temp, idx = 2;
    cin >> n;
    S.push(1);
    result.push('+');

    while (n--)
    {
        cin >> temp;
        if (S.top() <= temp)
        {
            int size = temp - S.top();
            while (size--)
            {
                S.push(idx);
                result.push('+');
                idx++;
            }
            S.pop();
            result.push('-');
        }
        else
        {
            possible = false;
        }
    }

    if (!possible)
    {
        cout << "No";
    }
    else
    {
        while (!result.empty())
        {
            cout << result.front() << '\n';
            result.pop();
        }
    }
}