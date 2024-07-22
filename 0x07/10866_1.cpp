// µ¦
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> DQ;
    int N;
    cin >> N;
    while (N--)
    {
        string command;
        cin >> command;
        if (command == "push_front")
        {
            int c;
            cin >> c;
            DQ.push_front(c);
        }
        else if (command == "push_back")
        {
            int c;
            cin >> c;
            DQ.push_back(c);
        }
        else if (command == "pop_front")
        {
            if (DQ.empty())
                cout << -1 << '\n';
            else
            {
                cout << DQ.front() << '\n';
                DQ.pop_front();
            }
        }
        else if (command == "pop_back")
        {
            if (DQ.empty())
                cout << -1 << '\n';
            else
            {
                cout << DQ.back() << '\n';
                DQ.pop_back();
            }
        }
        else if (command == "size")
        {
            cout << DQ.size() << '\n';
        }
        else if (command == "empty")
        {
            cout << (int)DQ.empty() << '\n';
        }
        else if (command == "front")
        {
            if (DQ.empty())
                cout << -1 << '\n';
            else
                cout << DQ.front() << '\n';
        }
        else if (command == "back")
        {
            if (DQ.empty())
                cout << -1 << '\n';
            else
                cout << DQ.back() << '\n';
        }
    }
}