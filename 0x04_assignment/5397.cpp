// Å°·Î°Å
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        list<char> password;
        list<char>::iterator cursor = password.begin();
        string str;
        cin >> str;
        for (char c : str)
        {
            if (c == '<')
            {
                if (cursor != password.begin())
                    cursor--;
            }
            else if (c == '>')
            {
                if (cursor != password.end())
                    cursor++;
            }
            else if (c == '-')
            {
                if (cursor != password.begin())
                {
                    cursor--;
                    cursor = password.erase(cursor);
                }
            }
            else
            {
                password.insert(cursor, c);
            }
        }
        for (char c : password)
            cout << c;
        cout << "\n";
    }
}