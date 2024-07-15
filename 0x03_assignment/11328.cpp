// strfry
#include <bits/stdc++.h>
using namespace std;

int alphabet[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string str1, str2;
    for (int i = 0; i < n; i++)
    {
        cin >> str1 >> str2;
        bool possible = true;

        if (str1.length() != str2.length())
        {
            possible = false;
        }
        else
        {
            fill(begin(alphabet), end(alphabet), 0); // alphabet 배열 초기화

            for (char c : str1)
                alphabet[c - 'a']++;

            for (char c : str2)
            {
                if (alphabet[c - 'a'] == 0)
                {
                    possible = false;
                    break;
                }
                alphabet[c - 'a']--;
            }
        }

        if (possible)
            cout << "Possible";
        else
            cout << "Impossible";
        cout << "\n";
    }
}
