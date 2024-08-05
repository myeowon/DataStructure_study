// 스타트 링크
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int building[1000000];
int F, S, G, U, D;
// 가장 높은 F
// 지금 있는 S
// 스타트링크 G
// 위로 U
// 아래로 D
queue<int> Q;

int d[2];
int main()
{
    cin >> F >> S >> G >> U >> D;

    d[0] = U;
    d[1] = -D;
    if (S == G)
    {
        cout << 0;
        return 0;
    }

    Q.push(S);
    building[S] = 1;
    while (!Q.empty())
    {
        int cur = Q.front();
        // cout << cur << ' ';
        Q.pop();
        for (int dir = 0; dir < 2; dir++)
        {
            int nxt = cur + d[dir];

            if (nxt < 1 || nxt > F) // 0층 없음
                continue;

            if (nxt == G)
            {
                cout << building[cur];
                return 0;
            }
            if (building[nxt] > 0)
                continue;
            Q.push({nxt});
            building[nxt] = building[cur] + 1;
        }
    }
    cout << "use the stairs";
}