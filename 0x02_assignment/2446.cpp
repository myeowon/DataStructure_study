// �� ��� - 9
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = N; i > 0; i--)
    {
        for (int j = 0; j < N - i; j++)
            cout << " ";
        for (int j = 0; j < 2 * i - 1; j++)
            cout << "*";
        cout << "\n";
    }
    for (int i = 2; i < N + 1; i++)
    {
        for (int j = 0; j < N - i; j++)
            cout << " ";
        for (int j = 0; j < 2 * i - 1; j++)
            cout << "*";
        cout << "\n";
    }
}
