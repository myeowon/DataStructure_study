// 0x01 강의 연습문제의 O(N) 풀이
#include <bits/stdc++.h>
using namespace std;

int func2(int arr[], int N)
{
    int temp[101] = {
        0,
    };
    for (int i = 0; i < N; i++)
    {
        if (temp[100 - arr[i]] != 1)
            temp[arr[i]] = 1;

        else
            return 1;
    }
    return 0;
}

int main()
{
    int arr1[] = {1, 52, 48};
    int arr2[] = {50, 42};
    int arr3[] = {4, 13, 63, 87};
    cout << func2(arr1, 3) << "\n"; // 1
    cout << func2(arr2, 2) << "\n"; // 0
    cout << func2(arr3, 4) << "\n"; // 1
}

// 데~~~~~~~~~`````성공!!