// ¹è¿­ queue
#include <bits/stdc++.h>
using namespace std;

const int MX = 100001;
int dat[MX];
int head = 0, tail = 0;

int size()
{
    return tail - head;
}

void push(int x)
{
    dat[tail++] = x;
}
void pop()
{
    head++;
}
int front()
{
    return dat[head];
}
int back()
{
    return dat[tail - 1];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string command;
    int e;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "push")
        {
            int e;
            cin >> e;
            push(e);
        }
        else if (command == "pop")
        {
            if (!size())
                cout << -1 << "\n";
            else
            {
                cout << front() << "\n";
                pop();
            }
        }
        else if (command == "size")
        {
            cout << size() << "\n";
        }
        else if (command == "empty")
        {
            if (!size())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (command == "front")
        {
            if (!size())
                cout << -1 << "\n";
            else
                cout << front() << "\n";
        }
        else if (command == "back")
        {
            if (!size())
                cout << -1 << "\n";
            else
                cout << back() << "\n";
        }
    }
}