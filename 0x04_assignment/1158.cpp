// 요세푸스 문제
// 원형 연결 리스트, 야매 연결 리스트

#include <bits/stdc++.h>
using namespace std;

const int MX = 5001;
int dat[MX], pre[MX], nxt[MX];

void erase(int addr)
{
    nxt[pre[addr]] = nxt[addr];
    pre[nxt[addr]] = pre[addr];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    for (int i = 1; i <= k; i++)
    {
        dat[i] = i;
        pre[i] = i - 1;
        nxt[i] = i + 1;
    }
    // 원형리스트 구현
    pre[1] = k;
    nxt[k] = 1;

    int remain = k;
    int cursor = 1;

    cout << "<";
    while (remain > 1)
    {
        for (int i = 0; i < n - 1; i++)
            cursor = nxt[cursor];

        cout << dat[cursor] << ", ";
        erase(cursor);
        cursor = nxt[cursor]; //!!
        remain--;
    }
    cout << dat[cursor];
    cout << ">";
}
