// ž
// pair ���
// pair : STL���� ������ ǥ���Ǵ� �ڷ����� ���� ����
// pair<(type1),(type2)> (name);
// 1. pair<int, int> p1 = {1,2}
// 2. pair<int, int> p2 = make_pair(2,2);
// - p1.first, p1.second�� ����
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<pair<int, int>> S;
    // first���� top�� ����
    // second���� top�� �ε���

    int N, height;
    cin >> N;

    S.push({100000001, 0});

    for (int i = 1; i < N + 1; i++)
    {
        cin >> height;
        while (S.top().first < height)
        {
            S.pop();
            // ���� ž���� ���� -> ū ž�鸸 �����
            // top �� ���̰� ���� ž���� ���� -> ����ž�� �ƴ� -> pop
            // top �� ���̰� ���� ž���� ŭ -> ����ž�� ã�� -> add
        }
        cout << S.top().second << ' ';
        S.push({height, i});
    }
}