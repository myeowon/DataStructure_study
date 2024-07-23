// 회전하는 큐
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count = 0;
    deque<int> DQ;

    int N, M, temp;
    cin >> N >> M;
    for (int i = 1; i < N + 1; i++)
        DQ.push_back(i);
    while (M--)
    {
        cin >> temp;
        if (DQ.front() == temp)
        {
            DQ.pop_front();
        }
        else
        {
            unsigned long long tempCnt = 0;
            while (DQ.front() != temp)
            {
                int front = DQ.front();
                DQ.pop_front();
                DQ.push_back(front);
                tempCnt++;
            }

            count += min(DQ.size() - tempCnt, tempCnt);
            DQ.pop_front();
        }
    }
    cout << count;
}