// ť : ī�� 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    int n;
    cin >> n;

    for (int i = 1; i < n + 1; i++)
        Q.push(i);
    while (Q.size()!=1)
    {
        Q.pop();
        int temp = Q.front();
        Q.pop();
        Q.push(temp);
    }
    cout << Q.front();
}