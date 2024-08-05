// 단지 번호 붙이기

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[27][27];
int vis[27][27];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N;
queue<pair<int, int>> Q;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++)
        {
            board[i][j] = line[j] - '0';
        }
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0 || vis[i][j] == 1)
                continue;
            int apartment = 1;
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
                    if (board[nx][ny] == 0 || vis[nx][ny] == 1)
                        continue;

                    Q.push({nx, ny});
                    vis[nx][ny] = 1;
                    apartment++;
                }
            }
            v.push_back(apartment);
        }
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << '\n';
    }
}