// ��!
// �������� �� ������ ��
// + Ż�� ���� ���� �Ǵ�
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[1001][1001];
int J[1001][1001];
int F[1001][1001];
int R, C;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ���� �� ������ �ð� ����α�
    // ������ ���
    // �����ڸ� �� Ȯ��

    pair<int, int> jihoon;
    cin >> R >> C;
    char temp;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> temp;

            if (temp == '.')
            {
                board[i][j] = 1;
            }
            else if (temp == '#')
            {
                board[i][j] = 0;
            }
            else if (temp == 'J')
            {
                // ������
                board[i][j] = 1; // ���� �Ϸ� ������
                J[i][j] = 1;
                jihoon = {i, j};
            }
            else if (temp == 'F')
            {
                // ���̾�~
                Q.push({i, j});
                F[i][j] = 1;
            }
        }
    }
    // ��
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;
            if (board[nx][ny] != 1 || F[nx][ny])
                continue;
            F[nx][ny] = F[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    // ������
    Q.push(jihoon);
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            {
                cout << J[cur.X][cur.Y];
                return 0;
            }

            if (board[nx][ny] != 1 || J[nx][ny] > 0)
                continue;
            if (F[nx][ny] == 0 || F[nx][ny] > J[cur.X][cur.Y] + 1)
            {
                J[nx][ny] = J[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}