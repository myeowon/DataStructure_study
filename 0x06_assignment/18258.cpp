// 큐2
// 별해 - 배열 + (?:) 사용해보기
#include <bits/stdc++.h>
using namespace std;

int n, h, t;
int q[2000000];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string command;
    cin >> n;
    while (n--)
    {
        cin >> command;
        if (command == "push")
            cin >> q[t++];
        else if (command == "pop")
            cout << (h == t ? -1 : q[h++]) << '\n';
        else if (command == "size")
            cout << t - h << '\n';
        else if (command == "empty")
            cout << (h == t ? 1 : 0) << '\n';
        else if (command == "front")
            cout << (h == t ? -1 : q[h]) << '\n';
        else if (command == "back")
            cout << (h == t ? -1 : q[t - 1]) << '\n';
    }
}