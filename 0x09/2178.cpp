// 미로 탐색
// 거리 측정
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
int vis[502][502];

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = line[j] - '0';
        }
    }

    vis[0][0] = 1;
    Q.push({0, 0});
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
            if (vis[nx][ny] > 0 || board[nx][ny] != 1)
                continue;

            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    int result = vis[n - 1][m - 1];
    cout << result;
    return 0;
}