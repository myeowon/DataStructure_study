// 쇠막대기
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<char> S;

    string str;
    cin >> str;

    int result = 0;
    bool preOpen = true;

    for (char c : str)
    {
        if (c == '(')
        {
            S.push(c);
            result++; // 쇠막대기 ++
            preOpen = true;
        }
        else if (c == ')')
        {
            S.pop();
            if (preOpen)
            {
                result--; // 쇠막대기가 아니였으므로 -1;
                result = result + S.size();
            }
            preOpen = false;
        }
    }
    cout << result;
}