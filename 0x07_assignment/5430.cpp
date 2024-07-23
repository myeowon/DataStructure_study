// AC
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        string p;
        cin >> p;
        bool reversed = false;
        bool error = false;

        int n;
        cin >> n;
        // �Ľ��Ͽ� ��� : ���ڸ� �̻� ���ڸ� �������� �� �Ͽ���.
        deque<int> DQ;
        string line;
        cin >> line;
        line = line.substr(1, line.size() - 2);
        stringstream ss(line);
        string c;
        while (getline(ss, c, ','))
        {
            DQ.push_back(stoi(c));
        }

        for (char c : p)
        {
            if (c == 'R')
            {
                reversed = !reversed;
            }
            else if (c == 'D')
            {
                if (!reversed) // not reversed, �տ� ������, empty?
                {
                    if (DQ.empty())
                        error = true;
                    else
                        DQ.pop_front();
                }
                else if (reversed) // reversed, �ڿ� ������, empty?
                {
                    if (DQ.empty())
                        error = true;
                    else
                        DQ.pop_back();
                }
            }
            else
            {
                cout << "error" << '\n';
            }
        }

        if (error)
        {
            cout << "error" << '\n';
        }
        else if (DQ.size() == 0)
        {
            cout << "[]" << '\n';
        }
        else if (!error && !reversed)
        {
            cout << "[";
            while (DQ.size() != 1)
            {
                cout << DQ.front() << ',';
                DQ.pop_front();
            }
            cout << DQ.front();
            cout << "]" << '\n';
        }
        else if (!error && reversed)
        {
            cout << "[";
            while (DQ.size() != 1)
            {
                cout << DQ.back() << ',';
                DQ.pop_back();
            }
            cout << DQ.back();
            cout << "]" << '\n';
        }
    }
}