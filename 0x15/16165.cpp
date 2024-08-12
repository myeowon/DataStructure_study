// 걸그룹 마스터 준석이
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, vector<string>> t2m;
unordered_map<string, string> m2t;

int T, Q;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T >> Q;
    while (T--)
    {
        string teamName;
        cin >> teamName;

        int members;
        cin >> members;

        vector<string> vecMembers;
        while (members--)
        {
            string memberName;
            cin >> memberName;
            m2t[memberName] = teamName;
            vecMembers.push_back(memberName);
        }
        t2m[teamName] = vecMembers;
        sort(t2m[teamName].begin(), t2m[teamName].end());
    }

    while (Q--)
    {
        string question;
        cin >> question;
        int questionCommand;
        cin >> questionCommand;
        if (questionCommand == 1)
        {
            cout << m2t[question] << '\n';
        }
        else
        {
            for (string m : t2m[question])
                cout << m << '\n';
        }
    }
}