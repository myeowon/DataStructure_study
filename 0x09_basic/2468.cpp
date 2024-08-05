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

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp, input;
            cin >> temp;
            if (temp > N)
                input = 1;
            else
                input = 0;
            board[i][j] = input;
        }
    }
    int result = 0;
    for (int n = 0; n <= N; n++)
    {
        int area;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 0 || vis[i][j] == 1)
                    continue;
                int area = 0;

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
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        if (board[nx][ny] == 0 || vis[nx][ny] == 1)
                            continue;
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                    }
                }
            }
        }
        if (area > result)
            result = area;
    }
    cout << result;
}