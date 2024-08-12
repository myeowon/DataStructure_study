// 패션왕 신해빈
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    while (N--)
    {
        int M;
        int ans = 1;
        cin >> M;
        unordered_map<string, int> m;
        while (M--)
        {
            string name, type;
            cin >> name >> type;
            m[type]++;
        }
        // 모든 경우의 수
        for (auto v : m)
            ans *= v.second + 1;
        cout << ans - 1 << '\n'; // 알몸인 경우를 제외합니다
    }
}