#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int32_t main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
       int k;
  cin >> k;
    double n = k;
  if(n <= 3){
      if(n == 1 || n == 2){
          cout << 1 << endl;

      }
      else if(n == 3){
          cout << 3 << endl;
      }
  }

  else{
      
      cout << (3 + static_cast<int>(((n-3)/2)*(8 + (n-4) * 2))) << endl;
  }
    }
}
