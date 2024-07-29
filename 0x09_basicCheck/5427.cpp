// 불

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int F[1002][1002];
int S[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int M, N;
        cin >> M >> N;
        queue<pair<int, int>> Q;
        pair<int, int> sang;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                char temp;
                cin >> temp;
                if (temp == '#') // 벽
                {
                    F[i][j] = -1;
                    S[i][j] = -1;
                }
                else if (temp == '*') // 불
                {
                    F[i][j] = 1;
                    S[i][j] = -1;
                    Q.push({i, j});
                }
                else if (temp == '.') // 빈 공간
                {
                    F[i][j] = 0;
                    S[i][j] = 0;
                }
                else if (temp == '@') // 상근이
                {
                    F[i][j] = 0;
                    S[i][j] = 1;
                    sang = {i, j};
                }
            }
        }
        if (sang.X == 0 || sang.Y == 0 || sang.X == N - 1 || sang.Y == M - 1)
        {
            cout << 1 << '\n';
            continue;
        }
        // 불 bfs
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (F[nx][ny] != 0 || F[nx][ny] == -1)
                    continue;
                F[nx][ny] = F[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }

        // 상근아 가자
        bool escape = false;
        int result = 0;
        Q.push(sang);
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if (F[nx][ny] == -1 && F[nx][ny] <= S[cur.X][cur.Y] + 1)
                    continue;

                if (S[nx][ny] > 0 || S[nx][ny] == -1)
                    continue;
                if (nx == 0 || ny == 0 || nx == N - 1 || ny == M - 1)
                {
                    result = S[cur.X][cur.Y] + 1;
                    escape = true;
                    break;
                }

                S[nx][ny] = S[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        if (escape)
        {
            cout << result << "\n";
        }
        else
        {
            cout << "IMPOSSIBLE" << "\n";
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                F[i][j] = 0;
                S[i][j] = 0;
            }
    }
}