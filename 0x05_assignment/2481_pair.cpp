// 탑
// pair 사용
// pair : STL에서 씽으로 표현되는 자료형을 위해 제공
// pair<(type1),(type2)> (name);
// 1. pair<int, int> p1 = {1,2}
// 2. pair<int, int> p2 = make_pair(2,2);
// - p1.first, p1.second로 참조
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int>> S;
    // first에는 top의 높이
    // second에는 top의 인덱스

    int N, height;
    cin >> N;

    S.push({100000001, 0});

    for (int i = 1; i < N + 1; i++)
    {
        cin >> height;
        while (S.top().first < height)
        {
            S.pop();
            // 작은 탑들은 제거 -> 큰 탑들만 남기기
            // top 의 높이가 현재 탑보다 작음 -> 수신탑이 아님 -> pop
            // top 의 높이가 현재 탑보다 큼 -> 수신탑을 찾음 -> add
        }
        cout << S.top().second << ' ';
        S.push({height, i});
    }
}