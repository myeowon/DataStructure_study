// πÊ πË¡§
#include <bits/stdc++.h>
using namespace std;

int boy[7];
int girl[7];
int result;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int students;
    float inOneRoom;
    cin >> students >> inOneRoom;

    int sex, grade;

    for (int i = 0; i < students; i++)
    {
        cin >> sex >> grade;
        if (sex == 0)
            boy[grade]++;
        else
            girl[grade]++;
    }
    for (int i = 1; i < 7; i++)
    {
        result += ceil(boy[i] / inOneRoom);
        result += ceil(girl[i] / inOneRoom);
    }
    cout << result;
}
