// 세수 정렬
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int list[3];

    cin >> list[0] >> list[1] >> list[2];

    sort(list, list + 3);

    for (int i = 0; i < 3; i++)
    {
        cout << list[i] << ' ';
    }
}