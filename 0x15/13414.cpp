// 나는야 포켓몬 마스터 이다솜

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> m;

bool cmp(pair<string, int> &a, pair<string, int> &b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; i++)
    {
        string num;
        cin >> num;

        m[num] = i;
    }

    vector<pair<string, int>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);

    int result = 0;
    for (auto e : vec)
    {
        result++;
        if (result > N)
            break;
        cout << e.first << '\n';
    }
}