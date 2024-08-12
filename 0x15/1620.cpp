// 나는야 포켓몬 마스터 이다솜

// 회사에 있는 사람
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> s2i;
string i2s[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> i2s[i];
        s2i[i2s[i]] = i;
    }

    while (M--)
    {
        string q;
        cin >> q;
        if (isdigit(q[0]))
        {
            cout << i2s[stoi(q)] << '\n';
        }
        else
        {
            cout << s2i[q] << '\n';
        }
    }
}