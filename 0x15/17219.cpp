// 비밀번호 찾기
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    while (N--)
    {
        string id, pwd;
        cin >> id >> pwd;
        m[id] = pwd;
    }
    while (M--)
    {
        string findId;
        cin >> findId;
        cout << m[findId] << '\n';
    }
}