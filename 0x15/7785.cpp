// 회사에 있는 사람
#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string name;
        string command;

        cin >> name >> command;
        if (command == "enter")
        {
            s.insert(name);
        }
        else if (command == "leave")
        {
            s.erase(name);
        }
    }

    vector<string> result(s.begin(), s.end());
    sort(result.begin(), result.end(), greater<string>()); // 역순정렬
    for (string n : result)
    {
        cout << n << '\n';
    }
}