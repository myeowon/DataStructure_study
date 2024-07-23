// 최솟값 찾기
#include <bits/stdc++.h>
using namespace std;

// 매번 새로운 창문 안에서의 최솟값을 출력
// 슬라이딩 윈도우 알고리즘

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> DQ;
    // num, index

    // 만약 앞에 원소가 뒤에 원소보다 작다?? 영원히 최솟값이 딜 수 없다....
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