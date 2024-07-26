// 토마토
// 시작점이 여러 개일 때
// 미리 시작점들을 큐에 넣어두기

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1001][1001];
int vis[1001][1001];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;
    int temp;

    int unripetoma = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            board[i][j] = temp;
            if (temp == 1)
            {
                Q.push({i, j});
                vis[i][j] = 1;
            }
            else if (temp == 0)
                unripetoma++;
        }
    }
    int result = 1;

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] != 0 || vis[nx][ny] > 0)
                continue;
            unripetoma--;
            if (result < vis[cur.X][cur.Y] + 1)
                result = vis[cur.X][cur.Y] + 1;

            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    if (unripetoma)
        cout << -1;
    else
        cout << result - 1;
}