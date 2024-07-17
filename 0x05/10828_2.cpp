// ¹è¿­ stack
#include <bits/stdc++.h>
using namespace std;

const int MX = 10001;
int dat[MX];
int pos = 0;

void push(int x)
{
    dat[pos++] = x;
}

void pop()
{
    pos--;
}

int top()
{
    return dat[pos - 1];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string command;

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
            if (pos == 0)
                cout << -1 << '\n';
            else
            {
                cout << top() << '\n';
                pop();
            }
        }
        else if (command == "size")
        {
            cout << pos << '\n';
        }
        else if (command == "empty")
        {
            if (pos == 0)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (command == "top")
        {
            if (pos == 0)
                cout << -1 << '\n';
            else
                cout << top() << '\n';
        }
        else
        {
            cout << "error" << "\n";
        }
    }
}