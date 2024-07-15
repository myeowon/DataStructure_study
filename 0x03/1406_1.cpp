// ������ STL ver.

#include <bits/stdc++.h>
using namespace std;

// N�� ũ�� ������ ���Ḯ��Ʈ�� ����

int main()
{
    string str;
    cin >> str;
    list<char> chars;
    for (char c : str)
        chars.push_back(c);
    list<char>::iterator cursor = chars.end();

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char command;
        cin >> command;
        if (command == 'L')
        {
            if (cursor != chars.begin())
                cursor--;
        }
        if (command == 'D')
        {
            if (cursor != chars.end())
                cursor++;
        }
        if (command == 'B')
        {
            if (cursor != chars.begin())
            {
                cursor--;
                cursor = chars.erase(cursor); // ���ŵ� ��Ҹ� ����Ű���� �����ؾ���
            }
        }
        if (command == 'P')
        {
            char newChar;
            cin >> newChar;
            chars.insert(cursor, newChar);
        }
    }
    for (char c : chars)
        cout << c;
}