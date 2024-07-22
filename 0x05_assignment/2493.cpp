// 탑
// 시간 초과 O(N^2)
#include <bits/stdc++.h>
using namespace std;

void tower(stack<int> S, int idx)
{
    int top = S.top();
    S.pop();
    while (!S.empty() && S.top() <= top)
    {
        idx--;
        S.pop();
    }
    cout << idx << ' ';
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t, i = 1;
    cin >> n;
    stack<int> S;
    while (n--)
    {
        cin >> t;
        S.push(t);
        tower(S, i - 1);
        i++;
    }
}