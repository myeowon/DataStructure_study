// �ּڰ� ã��
#include <bits/stdc++.h>
using namespace std;

// �Ź� ���ο� â�� �ȿ����� �ּڰ��� ���
// �����̵� ������ �˰���

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> DQ;
    // num, index

    // ���� �տ� ���Ұ� �ڿ� ���Һ��� �۴�?? ������ �ּڰ��� �� �� ����....
    for (int i = 1; i < N + 1; i++)
    {
        int num;
        cin >> num;

        while (!DQ.empty() && DQ.back().first >= num)
        {
            DQ.pop_back();
        }
        DQ.push_back({num, i});

        if (DQ.front().second <= i - L)
        {
            DQ.pop_front();
        }

        cout << DQ.front().first << ' ';
    }
}