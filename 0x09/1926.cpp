// �׸�
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
                continue; // ���� ��ĥ �Ǿ� ���� �ʰų� �湮�ϸ� �Ѿ��
            int count = 1;
            vis[i][j] = 1;  // (i, j)�� �湮�ߴٰ� ���
            Q.push({i, j}); // ť�� �������� (i, j)�� ����.

            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int dir = 0; dir < 4; dir++)
                { // �����¿� ĭ�� ���캼 ���̴�.
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue; // ���� ���� ��� �Ѿ
                    if (vis[nx][ny] == 1 || board[nx][ny] != 1)
                        continue;
                    count++;
                    vis[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
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

    // �׸��� ����, ���� ���� �׸��� ����
}