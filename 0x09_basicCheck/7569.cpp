// 도마도
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int tomato[10002][102];
int vis[10002][102];
int M, N, H;
int dx[6] = {0, 0, 1, -1};
int dy[6] = {1, -1, 0, 0, 0, 0};
// 같은 상자 안에서, 범위 조심
//+바로 윗층, 아랫층 +H, -H;
queue<pair<int, int>> Q;

void print()
{
    cout << "---------------------\n";
    for (int i = 0; i < N * H; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << tomato[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> H;
    int temp;
    int unripedtomato = 0;
    for (int i = 0; i < N * H; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> temp;
            tomato[i][j] = temp;
            if (temp == 1)
            {
                Q.push({i, j});
                vis[i][j] = 1;
            }
            if (temp == 0)
            {
                unripedtomato++;
            }
        }
    }
    if (!unripedtomato)
    {
        cout << 0;
        return 0;
    }
    dx[4] = N;
    dx[5] = -N;
    int result = 0;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 6; dir++)
        {

            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N * H || ny >= M)
                continue;
            if (dir < 4)
            {
                // 같은 층인지 확인?
                if (nx / N != cur.X / N)
                    continue;
            }
            if (tomato[nx][ny] == -1 || vis[nx][ny] == 1)
                continue;
            Q.push({nx, ny});
            tomato[nx][ny] = tomato[cur.X][cur.Y] + 1;
            if (result < tomato[nx][ny])
            {
                result = tomato[nx][ny];
            }
            vis[nx][ny] = 1;
            unripedtomato--;
        }
        // print();
    }

    if (unripedtomato)
        cout << -1;
    else
        cout << result - 1;
}