// ¿Ø±‚≥Û πË√ﬂ
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[51][51];
int vis[51][51];
int n, m, cab;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> cab;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                board[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        int cx, cy;
        while (cab--)
        {
            cin >> cx >> cy;
            board[cx][cy] = 1;
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 1)
                    continue;
                if (board[i][j] != 1)
                    continue;
                Q.push({i, j});
                vis[i][j] = 1;
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if (board[nx][ny] != 1 || vis[nx][ny] == 1)
                            continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                result++;
            }
        }
        cout << result << '\n';
    }
}