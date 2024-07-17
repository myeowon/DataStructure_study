// STL stack
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<int> S;
    string command;
    int e;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "push")
        {
            cin >> e;
            S.push(e);
        }
        else if (command == "pop")
        {
            if (S.size() == 0)
                cout << -1 << "\n";
            else
            {
                cout << S.top() << "\n";
                S.pop();
            }
        }
        else if (command == "size")
        {
            cout << S.size() << "\n";
        }
        else if (command == "empty")
        {
            if (S.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (command == "top")
        {
            if (S.empty())
                cout << -1 << "\n";
            else
                cout << S.top() << "\n";
        }
    }
}