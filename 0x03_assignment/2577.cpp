// 숫자의 개수
#include <bits/stdc++.h>
using namespace std;
int result[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    long long product = A * B * C;

    while (product > 0)
    {
        result[product % 10]++;
        product /= 10;
    }
    for (int i = 0; i < 10; i++)
        cout << result[i] << "\n";
}