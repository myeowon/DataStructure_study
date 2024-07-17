// STL queue
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    queue<int> Q;
    string command;
    int e;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "push")
        {
            cin >> e;
            Q.push(e);
        }
        else if (command == "pop")
        {
            if (Q.empty())
                cout << -1 << "\n";
            else
            {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (command == "size")
        {
            cout << Q.size() << "\n";
        }
        else if (command == "empty")
        {
            if (Q.empty())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (command == "front")
        {
            if (Q.empty())
                cout << -1 << "\n";
            else
                cout << Q.front() << "\n";
        }
        else if (command == "back")
        {
            if (Q.empty())
                cout << -1 << "\n";
            else
                cout << Q.back() << "\n";
        }
    }
}