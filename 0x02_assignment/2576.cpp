// È¦¼ö
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int sum = 0;
    int min = 100;
    int temp;
    for (int i = 0; i < 7; i++)
    {
        cin >> temp;
        if (temp % 2 != 0)
        {
            sum += temp;
            if (temp < min)
            {
                min = temp;
            }
        }
    }
    if (sum == 0)
    {
        cout << -1;
    }
    else
    {
        cout << sum << "\n"
             << min;
    }
}