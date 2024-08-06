// 상범 빌딩
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int L, R, C;
//
char board[902][32];
int vis[902][32];

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};

void reset()
{
    // for (int i = 0; i < L * R; i++)
    // {
    //     for (int j = 0; j < C; j++)
    //     {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for (int i = 0; i < L * R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            board[i][j] = 0;
            vis[i][j] = 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true)
    {
        cin >> L >> R >> C;
        if (L + R + C == 0)
        {
            return 0;
        }
        queue<pair<int, int>> Q;
        for (int i = 0; i < L * R; i++)
        {
            string line;
            cin >> line;
            for (int j = 0; j < C; j++)
            {
                board[i][j] = line[j];
                if (line[j] == 'S')
                {
                    Q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        dx[4] = R;
        dx[5] = -R;
        bool escape = false;
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 6; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (dir < 4 && cur.X / R != nx / R)
                    continue;
                if (nx < 0 || ny < 0 || nx >= L * R || ny >= C)
                    continue;

                if (board[nx][ny] == 'E')
                {
                    cout << "Escaped in " << vis[cur.X][cur.Y] << " minute(s)." << '\n';
                    escape = true;
                    break;
                }
                if (board[nx][ny] == '#' || vis[nx][ny] > 0)
                    continue;
                Q.push({nx, ny});
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            }
            if (escape)
                break;
        }
        if (!escape)
            cout << "Trapped!" << '\n';
        reset();
    }
}