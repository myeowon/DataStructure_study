// 빙산
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int ice[302][302];
int vis[302][302];
int tmp[302][302];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, M;
queue<pair<int, int>> Q;

int result = -1;

void resetVis()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            vis[i][j] = 0;
}
void printIce()
{
    cout << "-------------------------\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << ice[i][j] << ' ';
        }
        cout << '\n';
    }
}

void melt()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (ice[i][j] <= 0 || vis[i][j] == 1)
                continue;

            Q.push({i, j});
            vis[i][j] = 1;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                int zeroCnt = 0;
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                        continue;
                    if (ice[nx][ny] <= 0)
                    {
                        zeroCnt++;
                        continue;
                    }
                    if (vis[nx][ny] == 1)
                        continue;

                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
                tmp[cur.X][cur.Y] = ice[cur.X][cur.Y] - zeroCnt;
                if (tmp[cur.X][cur.Y] < 0)
                    tmp[cur.X][cur.Y] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ice[i][j] = tmp[i][j];
}

void areaCnt(int n)
{
    int area = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (ice[i][j] <= 0 || vis[i][j] == 1)
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
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                        continue;
                    if (vis[nx][ny] == 1 || ice[nx][ny] <= 0)
                        continue;

                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    if (area > 1)
        result = n;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> ice[i][j];

    for (int n = 0; n <= 10; n++)
    {
        melt();
        // printIce();
        resetVis();
        areaCnt(n);
        resetVis();
        if (result > -1)
            break;
    }
    if (result == -1)
    {
        cout << 0;
    }
    else
    {
        cout << result + 1;
    }
}