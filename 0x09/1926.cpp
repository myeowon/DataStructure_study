// 그림
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502];
bool vis[502][502];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

int main()

{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max = 0;
    int pics = 0;

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] != 1 || vis[i][j] == 1)
                continue; // 만약 색칠 되어 있지 않거나 방문하면 넘어가기
            int count = 1;
            vis[i][j] = 1;  // (i, j)을 방문했다고 명시
            Q.push({i, j}); // 큐에 시작점인 (i, j)을 삽입.

            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++)
                { // 상하좌우 칸을 살펴볼 것이다.
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue; // 범위 밖일 경우 넘어감
                    if (vis[nx][ny] == 1 || board[nx][ny] != 1)
                        continue;
                    count++;
                    vis[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
                    Q.push({nx, ny});
                }
            }
            if (max < count)
                max = count;
            pics++;
        }
    }
    cout << pics << '\n'
         << max;

    // 그림의 개수, 가장 넓은 그림의 넓이
}