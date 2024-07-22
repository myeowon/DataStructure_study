// µ¦
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x)
{
    dat[--head] = x;
}
void push_back(int x)
{
    dat[tail++] = x;
}
void pop_front()
{
    head++;
}
void pop_back()
{
    tail--;
}
int size()
{
    return tail - head;
}
bool empty()
{
    if (size())
        return 0;
    else
        return 1;
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
    int N;
    cin >> N;
    while (N--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push_front")
        {
            int c;
            cin >> c;
            push_front(c);
        }
        else if (cmd == "push_back")
        {
            int c;
            cin >> c;
            push_back(c);
        }
        else if (cmd == "pop_front")
        {
            if (empty())
                cout << -1 << '\n';
            else
            {
                cout << front() << '\n';
                pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if (empty())
                cout << -1 << '\n';
            else
            {
                cout << back() << '\n';
                pop_back();
            }
        }
        else if (cmd == "size")
        {
            cout << size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << empty() << '\n';
        }
        else if (cmd == "front")
        {
            if (empty())
                cout << -1 << '\n';
            else
                cout << front() << '\n';
        }
        else if (cmd == "back")
        {
            if (empty())
                cout << -1 << '\n';
            else
                cout << back() << '\n';
        }
    }
}