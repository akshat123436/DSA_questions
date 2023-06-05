// ------------Akshat Kothavade----------------
// -----------CC : Akshat123436-----------------

#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "," << #y << " = " << y << endl
#define PI 3.1415926535897932384626
#define endl '\n'

int mpow(int base, int exp); 

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

//          ------ LETS START 💫💫💫 -------

void solve() {
  int n;
  cin >> n;

  int total = pow(2,n);

  int arr[total];

  for(int i = 0; i<total ; i++){
      cin  >> arr[i];
  }
    sort(arr, arr+total);
    vector <vector<int>> summation(n);
    
  for(int i = 0; i<n; i++){
      
      int pair = pow(2,i);
      for(int j = 0; j<total;){
          int k = 0;
          int sum = 0;
          for(; k<pair; k++,j++){
            //   deb(i); deb(pair) deb(arr[j]);
              sum+=arr[j];
          }
          
          summation[i].push_back(sum);
      }
  }
    // for(auto a: summation){
    //     for(auto b : a){
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }
    int upper = summation.size();
    bool check = true;
    for(int i = 0; i<upper; i++){
        int size = summation[i].size();
        for(int j = 0; j<size-1; j++){
            if(summation[i][j+1] - summation[i][j] > 1){
                check = false;
                break;
            }
        }
    }
    if(check){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout << endl;
}

int32_t main() {
    // ios_base::sync_with_stdio(0), cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
      solve();
    }

    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((int)result * base) % mod;
    base = ((int)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

