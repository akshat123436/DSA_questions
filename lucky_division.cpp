// Author : Akshat Kothavade
// CC : Akshat123436

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
int mpow(int base, int exp); 

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

//          ------ LETS START 💫💫💫 -------

void solve() {
  int n;
  cin >> n;

  int arr[12] = {4, 7 ,  47,  74, 447, 444, 777, 477, 474, 744, 774, 747}; 
  bool is_almost = false;
  for(int i = 0; i<12 ;i++){
    if(n % arr[i] == 0){
      is_almost = true;
      break;
    }
  }
  if(is_almost){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    // cin >> t;
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

