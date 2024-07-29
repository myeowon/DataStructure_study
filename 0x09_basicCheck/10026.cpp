// 적록색약
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

char board[101][101];
int R[101][101];
int G[101][101];
int B[101][101];
int RnG[101][101];

queue<pair<int, int>> Q;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++)
            board[i][j] = line[j];
    }
    // normal
    // R
    int Rcnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != 'R' || R[i][j] == 1)
                continue;
            Q.push({i, j});
            R[i][j] = 1;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if (board[nx][ny] != 'R' || R[nx][ny] == 1)
                        continue;
                    Q.push({nx, ny});
                    R[nx][ny] = 1;
                }
            }
            Rcnt++;
        }
    }
    // G
    int Gcnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != 'G' || G[i][j] == 1)
                continue;
            Q.push({i, j});
            G[i][j] = 1;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if (board[nx][ny] != 'G' || G[nx][ny] == 1)
                        continue;
                    Q.push({nx, ny});
                    G[nx][ny] = 1;
                }
            }
            Gcnt++;
        }
    }
    // B
    int Bcnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] != 'B' || B[i][j] == 1)
                continue;
            Q.push({i, j});
            B[i][j] = 1;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if (board[nx][ny] != 'B' || B[nx][ny] == 1)
                        continue;
                    Q.push({nx, ny});
                    B[nx][ny] = 1;
                }
            }
            Bcnt++;
        }
    }
    // color - blinded
    // R & G
    int RnGcnt = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 'B' || RnG[i][j] == 1)
                continue;
            Q.push({i, j});
            RnG[i][j] = 1;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if (board[nx][ny] == 'B' || RnG[nx][ny] == 1)
                        continue;
                    Q.push({nx, ny});
                    RnG[nx][ny] = 1;
                }
            }
            RnGcnt++;
        }
    }

    // result :  R+G+B / R&G + B
    cout << Rcnt + Gcnt + Bcnt << ' ' << RnGcnt + Bcnt;
}