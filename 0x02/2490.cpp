// ¿∑≥Ó¿Ã

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d, sum;
    for (int i = 0; i < 3; i++)
    {
        cin >> a >> b >> c >> d;
        sum = a + b + c + d;
        switch (sum)
        {
        case 0:
            cout << "D";
            break;
        case 1:
            cout << "C";
            break;
        case 2:
            cout << "B";
            break;
        case 3:
            cout << "A";
            break;
        case 4:
            cout << "E";
            break;
        default:
            break;
        }
        cout << "\n";
    }
    return 0;
}
/*
πŸ≈∑µ∂ ver.

int result, input;
string res = "DCBAE";

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int r = 0; r < 3; r++) {
    result = 0;
    for(int c = 0; c < 4; c++) {
      cin >> input;
      result += input;
    }
    cout << res[result] << '\n';
  }
}

*/