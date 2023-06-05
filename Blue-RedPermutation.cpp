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

  int arr[n];

  for(int i = 0; i<n; i++){
      cin >> n;
  }

  string s;
  cin >> s;
    vector <int> red;
    vector <int> blue;
  for(int i = 0 ; i<n; i++){
      if(s[i] == 'R'){
          red.push_back(arr[i]);

      }
      else{
          blue.push_back(arr[i]);
      }
  }
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    int k = 0;
    int red_counter = 0;
    int blue_counter = 0;
    bool breaking_condition = false;
  for(int i = 1; i<=n; i++,k++){
      if(red[red_counter] <= num){
          
      }
      else{

      }
  }
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

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

