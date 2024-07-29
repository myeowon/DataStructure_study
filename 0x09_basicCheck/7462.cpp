// 나이트의 이동
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[302][302];
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int I;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> I;

        for (int i = 0; i < I; i++)
        {
            for (int j = 0; j < I; j++)
            {
                board[i][j] = 0;
            }
        }
        int curXpos, curYpos;
        int wantXpos, wantYpos;

        cin >> curXpos >> curYpos;
        cin >> wantXpos >> wantYpos;
        if (curXpos == wantXpos && curYpos == wantYpos)
        {
            cout << 0 << '\n';
            continue;
        }
        queue<pair<int, int>> Q;
        board[curXpos][curYpos] = 1;
        Q.push({curXpos, curYpos});

        int result = 0;
        bool foundIt = false;
        while (!Q.empty())
        {
            pair<int, int> cur = Q.front();
            Q.pop();

            for (int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if (nx < 0 || ny < 0 || nx >= I || ny >= I)
                    continue;
                if (nx == wantXpos && ny == wantYpos)
                {
                    foundIt = true;
                    result = board[cur.X][cur.Y];
                    break;
                }

                if (board[nx][ny] > 0)
                    continue;
                board[nx][ny] = board[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
            if (foundIt)
                break;
        }
        cout << result << '\n';
    }
}