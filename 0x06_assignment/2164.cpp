// ť2
// ���� - �迭 + (?:) ����غ���
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    queue<int> Q;

    if (N == 1) // N = 1�϶� �ٷ� ����
    {
        cout << 1;
    }
    else
    {
        // �ʱ� ����, ¦���� �־���
        for (int i = 0; i < N / 2; i++)
        {
            Q.push(2 * (i + 1));
        }

        for (int i = N; Q.size() != 1; i++)
        {
            if (i % 2 == 1)

            {
                int temp = Q.front();
                Q.pop();
                Q.push(temp);
            }
            else
            {
                Q.pop();
            }
        }
        cout << Q.front();
    }
}