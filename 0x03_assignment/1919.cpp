// 애너그램 만들기
#include <bits/stdc++.h>
using namespace std;
int alphabet[26];

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; i < str1.length(); i++)
        alphabet[str1[i] - 'a']++;

    for (int i = 0; i < str2.length(); i++)
        alphabet[str2[i] - 'a']--;

    int result = 0;
    for (int i = 0; i < 26; i++)
        result += abs(alphabet[i]);
    cout << result;
}
