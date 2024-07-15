// 카드 역배치
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    int card[21];
    for (int i = 1; i <= 20; i++)
        card[i] = i;
    for (int i = 0; i < 10; i++)
    {
        cin >> a >> b;
        for (int j = 0; j < (b - a) / 2 + 1; j++)
        {
            int temp = card[a + j];
            card[a + j] = card[b - j];
            card[b - j] = temp;
        }
    }

    for (int i = 1; i < 21; i++)
    {
        cout << card[i] << " ";
    }
}
/*
바킹독 ver.

int num[21];

// 카드를 역순으로 놓는 함수
void reverse(int a, int b){
  for(int i = 0; i < (b - a + 1) / 2; i++)
    swap(num[a+i], num[b-i]);
}

int main(void){

  for(int i = 1; i <= 20; i++) num[i] = i;

  for(int i = 1; i <= 10; i++) {
    int a, b;
    cin >> a >> b;
    reverse(a, b);
  }

  for(int i = 1; i <= 20; i++) cout << num[i] << ' ';
}
*/
/*
바킹독 STL ver.

int num[21];

int main(void){

  for(int i = 1; i <= 20; i++) num[i] = i;

  for(int i = 1; i <= 10; i++) {
    int a, b;
    cin >> a >> b;
    reverse(num+a, num+b+1);
  }

  for(int i = 1; i <= 20; i++) cout << num[i] << ' ';
}
*/