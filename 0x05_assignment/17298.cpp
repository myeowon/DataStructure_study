// ¿ÀÅ«¼ö
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, e;
    stack<int> T;

    cin >> n;

    while (n--)
    {
        cin >> e;
        T.push(e);
    }

    int max = -1;
    while (!T.empty())
    {
        cout << max << ' ';
        if (T.top() > max)
            max = T.top();
        T.pop();
    }
}