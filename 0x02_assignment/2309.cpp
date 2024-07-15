// ¿œ∞ˆ ≥≠¿Ô¿Ã
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int dwarf[9];
    int sum = 0;

    for (int i = 0; i < 9; i++)
    {
        cin >> dwarf[i];
        sum += dwarf[i];
    }
    sort(dwarf, dwarf + 9);
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 1; j < 9; j++)
        {
            if (sum - dwarf[i] - dwarf[j] == 100)
                break;
        }
        if (sum - dwarf[i] - dwarf[j] == 100)
            break;
    }

        for (int k = 0; k < 9; k++)
    {
        if (k != i && k != j)
        {
            cout << dwarf[k] << "\n";
        }
    }
    return 0;
}
