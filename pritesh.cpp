/*   ________  _____                       ______________
     _________ _____   IS THIS THE CODE EH?  _____________
                                                         :)(pR)
                                                                                                             */

#include <bits/stdc++.h>
using namespace std;

//definition
#define um unordered_map
#define vi vector<int>
#define vl vector<ld>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define mi map<int, int>
#define ml map<ll, ll>
#define sl set<ll>

//important constants
#define MOD 1000000007
#define INF 1LL << 57LL
#define MAX 1000000
#define pi 3.14159265358979
#define ESP (1e-9)

//looping
#define fr(i, a) for (i = 0; i < a; i++)
#define fe(i, a) for (i = 1; i <= a; i++)
#define frw(i, a, n) for (i = a; i < n; i++)
#define frwq(i, a, n) for (i = a; i <= n; i++)
#define revq(i, n, a) for (i = n; i >= a; i--)
//terms
#define ff first
#define ss second
#define rev(i, n, a) for (i = n; i > a; i--)
#define sz size()
#define clr clear()
#define len length()
#define pb push_back
#define mp make_pair
#define gcd(a, b) __gcd(a, b)
#define all(vi) vi.begin(), vi.end()
#define grtsrt(v) sort(v.begin(), v.end(), greater<int>())
#define lb lower_bound
#define ub upper_bound
#define nline '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x)     \
  cerr << #x << " "; \
  _print(x);         \
  cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
  cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
  cerr << "[ ";
  for (T i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
  cerr << "[ ";
  for (auto i : v)
  {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}

//
// long long calculate(long long p, long long q)
// {
//     long long  expo;
//     expo = MOD - 2;
//     // Loop to find the value
//     // until the expo is not zero
//     while (expo)
//     {
//         // Multiply p with q
//         // if expo is odd
//         if (expo & 1)
//         {
//             p = (p * q) % MOD;
//         }
//         q = (q * q) % MOD;
//         // Reduce the value of
//         // expo by 2
//         expo >>= 1;
//     }
//     return p;
// }
// ll fact(ll n)
// {
//     ll i=0, f=1;
//     for(i=1; i<=n; i++)
//         f = (f*i)%MOD;
//       // cout<<f<<nline;
//     return f;
// }

// // void seive(){

//   for(int i=0;i<N+1;i++)
//       spf[i]=i;
//     for(int i=2;i*i<=N;i++)
//     {
//       if(spf[i]==i)
//       {
//         for(int j=i*i;j<=N;j+=i)

//           if(spf[j]==[j])
//             spf[j]=i;
//       }
//     }

// }

// bool cmp(pair<pair<ll,ll>,ll> a,pair<pair<ll,ll>,ll> b)
// {
//   if(a.ss<b.ss)
//     return true;
//    return false;
// }

ll check_dude(ll mid, vll &v, ll n, ll sum)
{
  // vll a=v;
  // sort(all(a));
  // cout<<mid<<nline;
  ll main = mid * n - sum;
  ll x = (n + 1) / 2;
  x--;
  ll cost = 0;
  ll var = mid;
  // debug(a);
  if (main < 0)
    return -1;

  for (int i = x; i < n; i++)
  {
    if (mid > v[i])
    {
      cost += mid - v[i];
    }
  }
  // cout<<cost<<nline;
  if (cost > main)
  {
    return -1;
  }

  // var-=cost;
  // for(int i=0;i<x;i++){
  //     if(var<=0)
  //       break;
  //    if(main>a[i]){
  //        a[i]+=main-a[i];
  //        var-=main-a[i];
  //    }
  // }
  // sort(all(a));

  // if(a[x]==main)
  //   return main;

  return main;
}

ll bs(ll low, ll high, vll &v, ll n, ll sum)
{
  ll x = 0;
  while (low <= high)
  {
    // cout<<low<<" "<<high<<nline;
    ll mid = low + (high - low) / 2;
    // cout<<mid<<nline;
    if (check_dude(mid, v, n, sum) != -1)
    {
      // cout<<'a'<<nline;
      high = mid - 1;
      x = check_dude(mid, v, n, sum);
    }

    else
      low = mid + 1;
  }

  return x;
}

int main()
{

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
  // seive();
  // for(int i=1;i<=N;i++){
  //        if(prime[i])
  //          v.pb(i);

  //   }

  int t;
  cin >> t;
  while (t--)
  {
    ll n, k, i = 0;
    cin >> n >> k;
    ll step = 0;
    ll j = 1;

    if (n == 2)
    {
      if (k % 2 == 0)
        cout << 1 << " " << 2 << nline;
      else
        cout << 2 << " " << 1 << nline;

      continue;
    }
    // while (1)
    // {

    //   ll var = pow(2, j);
    //   ll x = INF;
    //   var++;

    //   ll val = n - 1;
    //   x = (var) % val;

    //   if (x == 2)
    //   {
    //     step = j;
    //     break;
    //   }

    //   j++;
    // }
    ll two = 2;
    int num = 2;
    int steps = 0;
    do
    {
      // cout << num << " ";
      if (num % two == 0)
      {
        num = n / two + num / two;
      }
      else
      {
        num = (num + ll(1)) / two;
      }
      // cout << i << " " << num << endl;

      // cout << num << endl;
      steps++;
    } while (2 != num);
    cout << steps << endl;
    step = steps;
    // cout<<j<<nline;
    // step = k % step;

    // ll diff = pow(2, step);
    // ll fam = 1;
    // cout << 1 << " ";
    // fe(i, n - 1)
    // {
    //   ll val = n;
    //   fam += diff;
    //   if (fam < n)
    //     // cout << fam << " ";
    //   else
    //   {

    //     val = n - 1;
    //     ll x = fam % val;
    //     if (x == 0)
    //       x = val;
    //     if (x == 1)
    //       x = n;
    //     // cout << x << " ";
    //   }
    // }

    // cout << nline;
  }

  return 0;
}