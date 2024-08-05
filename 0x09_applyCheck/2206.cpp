// 벽 부수고 이동하기
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1002][1002];
int vis[1002][1002];
int vis2[1002][1002];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int dx2[4] = {0, 0, -2, 2};
int dy2[4] = {2, -2, 0, 0};

int N, M;
queue<pair<int, int>> Q;
/*
bfs로 길을 찾기 - 배열에 시간 표시
이때 안 되면 -1 출력 return 0
도착지점에서부터 cur - 1 되는 방향으로 bfs돌면서 차이가 제일 큰거를 가져오기
차이가 1인거는 벽을 안 뚫은거
if [i][j] == [cur.X][cur.Y] -1 -> Q.push()
else if [i][j] < [cur.X][cur.Y] -> if([cur.X][cur.Y] - [i][j] > breakWall) -> breakWall =
*/
// https://www.acmicpc.net/board/view/119335
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = line[j] - '0';
        }
    }
    bool possible = false;
    Q.push({0, 0});
    vis[0][0] = 1;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        int wantToBreak = 4;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (board[nx][ny] == 1 || vis[nx][ny] > 0)
                continue;
            if (nx == N - 1 && ny == M - 1)
                possible = true;
            Q.push({nx, ny});
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        }
    }

    // if (!possible)
    // {
    //     Q.push({0, 0});
    //     vis2[0][0] = 1;
    //     while (!Q.empty())
    //     {
    //         pair<int, int> cur = Q.front();
    //         Q.pop();
    //         int wantToBreak = 4;
    //         for (int dir = 0; dir < 4; dir++)
    //         {
    //             int nx = cur.X + dx[dir];
    //             int ny = cur.Y + dy[dir];

    //             if (nx < 0 || ny < 0 || nx >= N || ny >= M)
    //             {
    //                 wantToBreak--;
    //                 continue;
    //             }

    //             if (board[nx][ny] == 1 || vis2[nx][ny] > 0)
    //             {
    //                 wantToBreak--;
    //                 continue;
    //             }

    //             if (nx == N - 1 && ny == M - 1)
    //                 possible = true;
    //             Q.push({nx, ny});
    //             vis2[nx][ny] = vis2[cur.X][cur.Y] + 1;
    //         }
    //         if (wantToBreak == 0 && breakSkill)
    //         {
    //             cout << cur.X << ' ' << cur.Y;
    //             for (int dir = 0; dir < 4; dir++)
    //             {
    //                 int nx = cur.X + dx2[dir];
    //                 int ny = cur.Y + dy2[dir];

    //                 if (nx < 0 || ny < 0 || nx >= N || ny >= M)
    //                     continue;
    //                 if (board[nx][ny] == 1 || vis2[nx][ny])
    //                     continue;
    //                 if (nx == N - 1 && ny == M - 1)
    //                     possible = true;
    //                 Q.push({nx, ny});
    //                 vis[nx][ny] = vis[cur.X][cur.Y] + 2;
    //                 cout << vis[nx][ny];
    //                 breakSkill = false;
    //                 break;
    //             }
    //         }
    //     }

    Q.push({0, 0});
    vis2[0][0] = 1;
    pair<int, int> breakthewall1 = {0, 0};
    pair<int, int> breakthewall2 = {0, 0};
    bool breakSkill = true;
    while (!Q.empty() && breakSkill)
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx2[dir];
            int ny = cur.Y + dy2[dir];

            int wallX = cur.X + dx[dir];
            int wallY = cur.Y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (board[wallX][wallY] != 1)
                continue; // 벽없는거스킵
            if (board[nx][ny] != 0 || vis2[nx][ny] > 0)
                continue; // 길인가
            if (nx == N - 1 && ny == M - 1)
                possible = true;

            if (vis[nx][ny] < vis[cur.X][cur.Y] + 2)
                continue;

            result = vis[cur.X][cur.Y] - vis[nx][ny];
        }
    }
    if (!possible)
    {
        cout << -1;
        return 0;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << vis2[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << vis[N - 1][M - 1];
        return 0;
    }
}