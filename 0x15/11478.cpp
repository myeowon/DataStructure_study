// 서로 다른 부분 문자열의 개수

#include <bits/stdc++.h>
using namespace std;
unordered_set<string> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    cin >> line;
    int L = line.length();
    for (int i = 1; i <= L; i++)
    { // 단어의 길이
        for (int j = 0; j + i <= L; j++)
        { // 시작
            string word = line.substr(j, i);
            m.insert(word);
        }
    }

    cout << m.size();
}