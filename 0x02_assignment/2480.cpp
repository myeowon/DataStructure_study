// 주사위 세개

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[3];
    int result;
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    if (arr[0] == arr[1] && arr[1] == arr[2])
    {
        result = 10000 + arr[2] * 1000;
    }
    else if (arr[0] == arr[1] || arr[1] == arr[2])
    {
        result = 1000 + arr[1] * 100;
    }
    else
    {
        result = arr[2] * 100;
    }
    cout << result;
}