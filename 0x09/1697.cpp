// 숨바꼭질
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dist[200001];
int N, K;
queue<int> Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    if (N == K)
    {
        cout << 0;
        return 0;
    } // 하...

    Q.push(N);
    dist[K] = -1;

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        int m[3] = {cur - 1, cur + 1, cur * 2};
        for (int i = 0; i < 3; i++)
        {
            int next = m[i];
            if (next < 0 || next >= 200001)
                continue;
            if (dist[next] > 0) // 이미 방문
                continue;
            dist[next] = dist[cur] + 1;
            if (next == K)
            {
                // 발견
                cout << dist[next];
                return 0;
            }
            Q.push(next);
        }
    }
}