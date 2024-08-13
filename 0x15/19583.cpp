// 싸이버개강총회

#include <bits/stdc++.h>
using namespace std;
unordered_set<string> m;

int toInt(string str)
{
    int strInt = 60 * stoi(str.substr(0, 2)) + stoi(str.substr(3, 2));
    return strInt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string start, end, close;
    cin >> start >> end >> close;

    int startInt = toInt(start);
    int endInt = toInt(end);
    int closeInt = toInt(close);

    int result = 0;
    string time, name;

    while (cin >> time >> name)
    {
        int timeInt = toInt(time);

        if (timeInt <= startInt)
        {
            m.insert(name);
        }
        else if (timeInt >= endInt && timeInt <= closeInt)
        {
            if (m.find(name) != m.end())
            {
                result++;
                m.erase(name);
            }
        }
    }
    cout << result;
    return 0;
}