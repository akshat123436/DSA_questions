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
int mpow(int base, int exp); 

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

//          ------ LETS START 💫💫💫 -------

void solve() {
  int n;
  cin >> n;
  vector <int> arr0, arr1, arrt;
  int sum0 {};
  for(int i = 0;i <n ;i++){
      int temp; 

      cin >> temp;
      if((i&1) == 1){
          arr1.push_back(temp);
      }
      else{
          arr0.push_back(temp);
          arrt.push_back(temp);
          sum0+=temp;
      }
  }

    sort(arr0.begin(), arr0.end());
        sort(arrt.begin(), arrt.end());

    sort(arr1.begin(), arr1.end());
    
    int size0 = arr0.size();
        int size1 = arr1.size();
    arr0[size0-1] = sum0;
    for(int i = 1; i<size0-1; i++){
        arr0[i] += arr0[i-1];
    }    

    for(int i = size0-2; i>=0; i--){
        // deb(sum0);
        // sum0 -= arrt[i+1];
        arr0[i] = sum0 - arr0[i];
    }
    // for(int i = 1; i<size1; i++){
    //     arr1[i] += arr1[i-1];
    // }
    sort(arr0.begin(), arr0.end());
    int ans = 0;
    
    // deb(size0); deb(size1);
    // for(int i = 0  ;i<size0; i++){
    //     cout << arr0[i] << " " << arr1[i] << endl;
    // }
    if((n&1) == 1){
        arr0.pop_back();
    }
    size0 = arr0.size();
    int k = size0 - 1;
    for(int i = 0; i<size1; i++){
                // deb(arr0[k]);  deb(arr1[size1 - i - 1]); deb(ans) ;

        ans += arr1[size1 - i - 1] * arr0[k];
        k--;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

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

