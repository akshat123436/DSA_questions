#include <bits/stdc++.h>

using namespace std;

#define fastio()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define maxi 1e7 + 10;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
  cerr << endl;
#else
#define debug(x)
#endif

/*void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}*/

int main()
{

#ifndef ONLINE_JUDGE

  freopen("Error.txt", "w", stderr);

#endif

  int t = 1;

  cin >> t;

  while (t--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int mx = *max_element(all(a));
    if (n * mx < k)
    {
      cout << -1 << '\n';
      continue;
    }
    int ans = n + 1;
    for (int b = 0; b < k; b++)
    {
      int to = -2;
      for (int i = 0; i < n - 1; i++)
      {
        if (a[i] < a[i + 1])
        {
          to = i;
          break;
        }
      }
      ans = to + 1;
      if (to == -2)
        break;
      a[to]++;
    }
    cout << ans << '\n';
  }
}

// /*   ________  _____                       ______________
//      _________ _____   IS THIS THE CODE EH?  _____________
//                                                          :)(pR)
//                                                                                                              */

// #include <bits/stdc++.h>
// using namespace std;

// //definition
// #define um unordered_map
// #define vi vector < int >
// #define vl vector < ld >
// #define vll vector < ll >
// #define pii pair <int, int>
// #define pll pair<ll, ll>
// #define vpii vector< pii >
// #define vpll vector< pll >
// #define mi   map<int,int>
// #define ml   map<ll,ll>

// //important constants
// #define MOD 1000000007
// #define INF 1LL<<57LL
// #define MAX 1000000
// #define pi 3.14159265358979
// #define ESP (1e-9)

// //looping
// #define fr(i,a) for(i=0;i<a;i++)
// #define fe(i,a) for(i=1;i<=a;i++)
// #define frw(i,a,n) for(i=a;i<n;i++)
// #define frwq(i,a,n) for(i=a;i<=n;i++)
// #define rev(i,n,a) for(i=n;i>a;i--)
// #define revq(i,n,a) for(i=n;i>=a;i--)
// //terms
// #define ff first
// #define ss second
// #define sz size()
// #define clr clear()
// #define len length()
// #define pb push_back
// #define mp make_pair
// #define gcd(a,b)  __gcd(a,b)
// #define all(vi) vi.begin(), vi.end()
// #define nline '\n'
// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;
// // typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
// #else
// #define debug(x)
// #endif

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// // bool prime[N];

// // void seive(){
// //    prime[1]=false,prime[0]=false;
// //   for(int i=2;i<N;i++)
// //       prime[i]=true;
// //     for(int i=2;i*i<=N;i++)
// //     {
// //       if(prime[i]==true)
// //       {
// //         for(int j=i*i;j<=N;j+=i)
// //           prime[j]=false;
// //       }
// //     }
// // }
// //
// bool cmp(pll a,pll b)
// {
//   if(a.ff>a.ss)
//     return true;
//    return false;
// }

// int main()
// {

//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    #ifndef ONLINE_JUDGE
//   freopen("Error.txt", "w", stderr);
// #endif
//   // seive();

//   int t;
//   cin>>t;
//   while(t--)
//   {
//     ll n,k,i=0,check=0,var=0,z=0,l=0;
//     cin>>n>>k;
//     bool known=true;
//     vll v1(n,0),v2,arr;
//     fr(i,n){
//        cin>>v1[i];
//     }

//        fr(i,n-1){
//           ll x=v1[i]-v1[i+1];
//           v2.pb(x);

//         }

//       map <int, int> m;

//       for(int i = 1;i<n-1;i++){
//           if(v1[i] > v1[i+1] && v1[i] > v1[i-1]){
//               m[v1[]]
//           }
//       }
//        if(k>var)
//         known=false;
//       ll x=min(k,var);
//       // cout<<x<<nline;

//       while(x--)
//       {
//         // cout<<'a'<<nline;
//           fr(i,v2.sz){
//                if(i==0&&v2[i]<0)
//                 {v2[i]++;
//                   arr.pb(i+1);
//                   break;}
//                else if(v2[i]<0&&i>0)
//                {
//                 v2[i-1]--;
//                 v2[i]++;
//                 arr.pb(i+1);
//                 break;
//                }

//           }
//       }
//       debug(v2);
//       debug(arr);
//       if(known)
//         cout<<arr[k-1]<<nline;
//       else
//         cout<<-1<<nline;

//   }
// return 0;

// }