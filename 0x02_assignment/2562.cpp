// 최댓값
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int temp, index, max = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> temp;
        if (temp > max)
        {
            index = i;
            max = temp;
        }
    }
    cout << max << "\n";
    cout << index + 1;
}
// max를 전역변수로 -> // 전역변수의 초기값은 0

/*
바킹독 max_element
int a[9];
int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 0; i < 9; i++) cin >> a[i];
  cout << *max_element(a, a+9) << '\n';
  cout << max_element(a, a+9) - a + 1;
}
*/
