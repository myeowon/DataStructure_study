// 영역 구하기
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[102][102];
int vis[102][102];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int M, N, K;
queue<pair<int, int>> Q;

int main()
{
    cin >> M >> N >> K;
    while (K--)
    {
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        for (int i = a2; i < b2; i++)
        {
            for (int j = a1; j < b1; j++)
            {
                board[i][j] = 1;
            }
        }
    }

    vector<int> vec;
    int idx = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (vis[i][j] == 1 || board[i][j] == 1)
                continue;
            int result = 1;
            Q.push({i, j});
            vis[i][j] = 1;
            idx++;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                        continue;
                    if (vis[nx][ny] == 1 || board[nx][ny] == 1)
                        continue;
                    result++;
                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
            vec.push_back(result);
        }
    }
    cout << idx << '\n';
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ' ';
    }
}