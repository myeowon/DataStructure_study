// 알파벳 개수
#include <bits/stdc++.h>
using namespace std;

int alphabet[26];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string word;
    cin >> word;
    for (int i = 0; i < word.length(); i++)
        alphabet[word[i] - 'a']++;
    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << " ";
    }
}
// 대~~~~~~~~성공!