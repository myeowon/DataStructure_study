// 개수 세기
#include <bits/stdc++.h>
using namespace std;

int result[201];

int main()
{
    int n, temp, v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        result[100 + temp]++;
    }
    cin >> v;
    cout << result[100 + v];
}
