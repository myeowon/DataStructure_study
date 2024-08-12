// 싸이버개강총회

#include <bits/stdc++.h>
using namespace std;
unordered_set<string> m;

pair<int, int> startInt;
pair<int, int> endInt;
pair<int, int> closeInt;
pair<int, int> toInt(string str)
{
    str.erase(remove(str.begin(), str.end(), ':'), str.end());
    int strInt = stoi(str);
    return {strInt / 100, strInt % 100};
}

bool beforeStart(pair<int, int> timeInt)
{
    if (timeInt.first < startInt.first)
        return true;
    else if (timeInt.first == startInt.first && timeInt.second <= startInt.second)
        return true;
    return false;
}
bool afterEnd_BeforeClose(pair<int, int> timeInt)
{
    if (timeInt.first > endInt.first || (timeInt.first == endInt.first && timeInt.second >= endInt.second))
        if (timeInt.first < closeInt.first || (timeInt.first == closeInt.first && timeInt.second <= closeInt.second))
            return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string start, end, close;
    cin >> start >> end >> close;
    startInt = toInt(start);
    endInt = toInt(end);
    closeInt = toInt(close);
    int result = 0;
    while (true)
    {
        string time;
        cin >> time;
        pair<int, int> timeInt = toInt(time);

        string name;
        cin >> name;
        if (cin.eof() == true)
            break;

        if (beforeStart(timeInt))
        {
            m.insert(name);
        }
        else if (afterEnd_BeforeClose(timeInt))
        {
            if (m.find(name) != m.end())
            {
                result++;
                m.erase(name);
            }
        }
    }
    cout << result;
}