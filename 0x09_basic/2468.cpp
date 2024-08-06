// 안전 영역
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[102][102];
int vis[102][102];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N;
queue<pair<int, int>> Q;

void resetVis()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            vis[i][j] = 0;
}
void printVis()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << vis[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    int max = 1;
    for (int n = 0; n <= 100; n++)
    {
        int area = 0; // 높이가 n일때 영역 개수
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] <= n || vis[i][j] == 1)
                    continue;
                area++;

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
                        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                            continue;
                        if (board[nx][ny] <= n || vis[nx][ny] == 1)
                            continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        if (area > max)
            max = area;

        // printVis();
        resetVis();
    }
    cout << max;
}