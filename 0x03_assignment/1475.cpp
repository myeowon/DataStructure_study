// ¹æ ¹øÈ£
#include <bits/stdc++.h>
using namespace std;

int result[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int room;
    cin >> room;
    while (room > 0)
    {
        result[room % 10]++;
        room /= 10;
    }
    result[6] = ceil((result[6] + result[9]) / 2.0);
    result[9] = 0;

    cout << *max_element(result, result + 10);
}