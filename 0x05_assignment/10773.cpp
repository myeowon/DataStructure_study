// Á¦·Î STL
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int n;
    cin >> n;

    while (n--)
    {
        int temp;
        cin >> temp;
        if (temp)
            S.push(temp);
        else
            S.pop();
    }

    long long sum = 0;
    while (!S.empty())
    {
        sum += S.top();
        S.pop();
    }
    cout << sum;
}