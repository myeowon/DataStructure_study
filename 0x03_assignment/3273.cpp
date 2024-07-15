// 두 수의 합
#include <bits/stdc++.h>
using namespace std;

int resultArr[2000001];
int arr[100001];
int result;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (x - arr[i] > 0 && resultArr[x - arr[i]] > 0)
            result++;
        resultArr[arr[i]]++;
    }

    cout << result;
}