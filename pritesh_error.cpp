// // /*   ________  _____                       ______________
// //      _________ _____   IS THIS THE CODE EH?  _____________
// //                                                          :)(pR)
// //                                                                                                              */

// // #include <bits/stdc++.h>
// // using namespace std;
// // typedef long long unsigned llu;
// // typedef long long ll;
// // typedef long l;

// // //definition
// // #define vi vector < int >
// // #define vl vector < ld >
// // #define vll vector < ll >
// // #define pii pair <int, int>
// // #define pll pair<ll, ll>
// // #define vpii vector< pii >
// // #define vpll vector< pll >
// // #define mi   map<int,int>
// // #define ml   map<ll,ll>

// // //important constants
// // #define MOD 1000000007
// // #define INF 1LL<<57LL
// // #define MAX 1000000
// // #define pi 3.14159265358979
// // #define ESP (1e-9)

// // //looping
// // #define fr(i,a) for(i=0;i<a;i++)
// // #define fe(i,a) for(i=1;i<=a;i++)
// // #define frw(i,a,n) for(i=a;i<n;i++)
// // #define frwq(i,a,n) for(i=a;i<=n;i++)
// // #define rev(i,n,a) for(i=n;i>a;i--)
// // #define revq(i,n,a) for(i=n;i>=a;i--)
// // //terms
// // #define ff first
// // #define ss second
// // #define sz size()
// // #define clr clear()
// // #define len length()
// // #define pb push_back
// // #define mp make_pair
// // #define gcd(a,b)  __gcd(a,b)
// // #define all(vi) vi.begin(), vi.end()

// // int main()
// // {
// //     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// //     int t;
// //     cin>>t;
// //     while(t--)
// //     {
// //      ll n,i=0,mini=INF,check=0;
// //      cin>>n;
// //      vll v1;
// //      vpll v2;
// //      fr(i,n)
// //      {
// //         ll x;
// //         cin>>x;
// //         v1.pb(x);
// //      }
// //      sort(all(v1));

// //       if(n==2)
// //         cout<<0<<endl;
// //     else if(n==3)
// //         cout<<min(v1[1]-v1[0],v1[2]-v1[1])<<endl;
// //     else
// //     {
// //      frw(i,1,n-1)
// //      {
// //         ll x=v1[i]-v1[0];
// //         v2.pb({x,i});
// //      }
// //       frw (i,1,n-1)
// //      {
// //         v2.pb({v1[n-1]-v1[i],-i});
// //      }
// //     sort(all(v2));
// //     // for(auto &it: v2)
// //     //     cout<<it.ff<<" "<<it.ss<<endl;
// //     fr(i,n)
// //     {
// //         // if(i<n-2&&v1[i]!=v1[i+1]&&v1[i+1]==v1[i+2])
// //         //  {check=v2[i].ff;
// //         //     cout<<v2[i].ff<<endl;
// //         //  }
// //         // // cout<<check<<endl;
// //         // if(v2[i].ff==v2[i+1].ff)
// //         // {
// //         //     // cout<<'a'<<endl;
// //         // if(abs(v2[i].ss)!=abs(v2[i+1].ss)&&(abs(v2[i].ss)+abs(v2[i+1].ss))==n&&v2[i].ss+v2[i+1].ss>=0)
// //         // {
// //         //     cout<<v2[i+1].ff<<" "<<v2[i].ff<<endl;

// //         //     mini=min(mini,v2[i+1].ff-check);
// //         // }
// //         // }
// //         cout<<v2[i].ff<<" "<<v2[i].ss<<endl;
// //         if(abs(v2[i].ss)!=abs(v2[i+1].ss)&&(abs(v2[i].ss)+abs(v2[i+1].ss))==n&&((v2[i].ss+v2[i+1].ss)>=0))
// //         {
// //             cout<<v2[i].ff<<" "<<v2[i].ss<<endl;
// //             mini=min(mini,(v2[i+1].ff-v2[i].ff));
// //         }
// //         // else if(v2[i].ss==v2[i+1].ss&&v2[i+1]==v2[i+2]&&i!=n-2)
// //         //    mini=min(mini,v2[i+2].ff-v2[i].ff);
// //     }

// //      cout<<mini<<endl;
// //  }

// //    }

// //     return 0;

// // }

// /*   _  _                       ___
//      _ _   IS THIS THE CODE EH?  ___
//                                                          :)(pR)
//                                                                                                              */

// #include <bits/stdc++.h>
// using namespace std;

// //definition
// #define um unordered_map
// #define vi vector<int>
// #define vl vector<ld>
// #define vll vector<ll>
// #define pii pair<int, int>
// #define pll pair<ll, ll>
// #define vpii vector<pii>
// #define vpll vector<pll>
// #define mi map<int, int>
// #define ml map<ll, ll>
// #define sl set<ll>

// //important constants
// #define MOD 1000000007
// #define INF 1LL << 57LL
// #define MAX 1000000
// #define pi 3.14159265358979
// #define ESP (1e-9)

// //looping
// #define fr(i, a) for (i = 0; i < a; i++)
// #define fe(i, a) for (i = 1; i <= a; i++)
// #define frw(i, a, n) for (i = a; i < n; i++)
// #define frwq(i, a, n) for (i = a; i <= n; i++)
// #define revq(i, n, a) for (i = n; i >= a; i--)
// //terms
// #define ff first
// #define ss second
// #define rev(i, n, a) for (i = n; i > a; i--)
// #define sz size()
// #define clr clear()
// #define len length()
// #define pb push_back
// #define mp make_pair
// #define gcd(a, b) __gcd(a, b)
// #define all(vi) vi.begin(), vi.end()
// #define grtsrt(v) sort(v.begin(), v.end(), greater<int>())
// #define lb lower_bound
// #define ub upper_bound
// #define nline '\n'
// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;
// // typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

// #ifndef ONLINE_JUDGE
// #define debug(x)       \
//     cerr << #x << " "; \
//     _print(x);         \
//     cerr << endl;
// #else
// #define debug(x)
// #endif

// void _print(ll t)
// {
//     cerr << t;
// }
// void _print(int t) { cerr << t; }
// void _print(string t) { cerr << t; }
// void _print(char t) { cerr << t; }
// void _print(lld t) { cerr << t; }
// void _print(double t) { cerr << t; }
// void _print(ull t) { cerr << t; }

// template <class T, class V>
// void _print(pair<T, V> p);
// template <class T>
// void _print(vector<T> v);
// template <class T>
// void _print(set<T> v);
// template <class T, class V>
// void _print(map<T, V> v);
// template <class T>
// void _print(multiset<T> v);
// template <class T, class V>
// void _print(pair<T, V> p)
// {
//     cerr << "{";
//     _print(p.ff);
//     cerr << ",";
//     _print(p.ss);
//     cerr << "}";
// }
// template <class T>
// void _print(vector<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T>
// void _print(set<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T>
// void _print(multiset<T> v)
// {
//     cerr << "[ ";
//     for (T i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }
// template <class T, class V>
// void _print(map<T, V> v)
// {
//     cerr << "[ ";
//     for (auto i : v)
//     {
//         _print(i);
//         cerr << " ";
//     }
//     cerr << "]";
// }

// //
// // long long calculate(long long p, long long q)
// // {
// //     long long  expo;
// //     expo = MOD - 2;
// //     // Loop to find the value
// //     // until the expo is not zero
// //     while (expo)
// //     {
// //         // Multiply p with q
// //         // if expo is odd
// //         if (expo & 1)
// //         {
// //             p = (p * q) % MOD;
// //         }
// //         q = (q * q) % MOD;
// //         // Reduce the value of
// //         // expo by 2
// //         expo >>= 1;
// //     }
// //     return p;
// // }
// // ll fact(ll n)
// // {
// //     ll i=0, f=1;
// //     for(i=1; i<=n; i++)
// //         f = (f*i)%MOD;
// //       // cout<<f<<nline;
// //     return f;
// // }
// // const int N=1e6;
// // bool prime[N+1];
// // void seive(){
// //    prime[0]=0;
// //    prime[1]=0;
// //   for(int i=2;i<N+1;i++)
// //       prime[i]=true;
// //     for(int i=2;i*i<=N;i++)
// //     {
// //       if(prime[i])
// //       {
// //         for(int j=i*i;j<=N;j+=i)
// //            prime[j]=0;
// //       }
// //     }

// // }

// bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
// {
//     if (a.ss < b.ss)
//         return true;
//     return false;
// }

// bool checker(int val)
// {

//     bool allset = 1;
//     int var = val;
//     // cout<<val<<nline;
//     while (var)
//     {
//         // cout<<var<<nline;
//         if (var & 1)
//         {
//             // cout<<'a'<<nline;
//         }
//         else
//             return false;
//         var = var >> 1;
//     }

//     return true;
// }

// int main()
// {

//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("Error.txt", "w", stderr);
// #endif
//     // seive();
//     // for(int i=1;i<=N;i++){
//     //        if(prime[i])
//     //          v.pb(i);

//     //   }

//     // int t;
//     // cin >> t;
//     // while (t--)
//     // {
//     int a = 2;

//     cout << a * 2LL << endl;
//     // ll a, b, i = 0;
//     // cin >> a >> b;

//     // ll x = a;
//     // ll y = b, ind = 0, ind1 = 0;

//     // ll ans = 0;

//     // while (x)
//     // {

//     //     if (x & 1)
//     //         ind = i;
//     //     i++;
//     //     x = x >> 1;
//     // }
//     // i = 0;

//     // while (y)
//     // {
//     //     if (y & 1)
//     //     {
//     //         ind1 = i;
//     //     }
//     //     i++;
//     //     y = y >> 1;
//     // }

//     // ind++;
//     // ind1++;
//     // debug(ind); debug(ind1);
//     // frw(i, ind + 1, ind1)
//     // {
//     //     ans += (i - 1);
//     // }
//     // debug(ans);
//     // // cout << ans << nline;
//     // debug(ind); debug(ind1);
//     // cout << (1<<ind) << endl;

//     // ll val = (ll(1) << (ind));
//     // ll var = (ll(1) << (ind1));
//     // debug(val); debug(var);
//     // val--;
//     // var--;
//     // debug(val); debug(var);
//     // // cout << val << " " << var << nline;

//     // ll low1 = 0, low2 = 0, in1 = (ind - 2), in2 = (ind1 - 2);
//     // while (1)
//     // {
//     //     if (in1 < 0)
//     //         break;
//     //     ll z = val - (ll(1) << in1);
//     //     // cout<<z<<nline;
//     //     if (z >= a && b >= z)
//     //         low1++;
//     //     in1--;
//     // }
//     // while (1)
//     // {
//     //     if (in2 < 0)
//     //         break;
//     //     ll z = var - (ll(1) << in2);
//     //     // cout<<z<<nline;
//     //     if (z <= b && z >= a)
//     //         low2++;
//     //     in2--;
//     // }
//     // // cout << low1 << " " << low2 << nline;
//     // ans += low2;
//     // // ans+=(ind-low1-1);
//     // ans += low1;

//     // cout << ans << nline;

//     // // }

//     return 0;
// }

// Lets goto the next level
// AIM CM at CF *__* asap
// Striver_79
// Remember you were also a novice when you started,
// hence never be rude to anyone who wants to learn something
// Never open a ranklist untill and unless you are done with solving problems, wastes 3/4 minuts
// Donot treat CP as a placement thing, love it and ejoy it, you will suceed for sure.
// Any doubts or want to have a talk, contact https://www.facebook.com/raj.striver

#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define mod (int)1000000007
#define all(a) a.begin(), a.end()
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define loop(i, a, b) for (int i = a; i < b; i++)
#define bloop(i, a, b) for (int i = a; i >= b; i--)
#define tc(t) \
    int t;    \
    cin >> t; \
    while (t--)
#define int long long
#define ll long long
#define pb emplace_back
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define in(x) scanf("%d", &x)
#define rr return 0
#define prec(n) fixed << setprecision(n)
#define maxpq priority_queue<int>
#define minpq priority_queue<int, vector<int>, greater<int>>
#define inf (int)(1e18)
#define ini(a, i) memset(a, i, sizeof(a))
#define vi vector<int>
#define fi first
#define se second
#define kitna se
#define endl "\n"
#define pi pair<int, int>
#define vii vector<pi>
const int MAXN = (int)((1e5) + 10);
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
bool isPrime(int N)
{
    for (int i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
int cbrt(int x)
{
    int lo = 1, hi = min(2000000ll, x);
    while (hi - lo > 1)
    {
        int mid = (lo + hi) / 2;
        if (mid * mid * mid < x)
        {
            lo = mid;
        }
        else
            hi = mid;
    }
    if (hi * hi * hi <= x)
        return hi;
    else
        return lo;
}
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int N = (int)(250005);
const int MAXBIT = 19;
//vector<int>vec[nax];
// const int N = 5;

// int SPF[N+5];

// void SOF()
// {
//     SPF[1] = 1;
//     for (int i=2; i<N; i++)
//         SPF[i] = i;
//     for (int i=4; i<N; i+=2)
//         SPF[i] = 2;

//     for (int i=3; i*i<N; i++)
//         {
//         if (SPF[i] == i)
//             {
//             for (int kon=i*i; kon<N; kon+=i)
//                 if (SPF[kon]==kon)
//                    SPF[kon] = i;
//             }
//         }
// }

// int C[1005][1005];
// int binomialCoeff(int n, int k)
// {
//     // int C[n + 1][k + 1];
//     int i, j;

//     // Caculate value of Binomial Coefficient
//     // in bottom up manner
//     for (i = 0; i <= n; i++)
//     {
//         for (j = 0; j <= min(i, k); j++)
//         {
//             // Base Cases
//             if (j == 0 || j == i)
//                 C[i][j] = 1;

//             // Calculate value using previosly
//             // stored values
//             else
//                 C[i][j] = C[i - 1][j - 1] +
//                           C[i - 1][j];
//         }
//     }

//     return C[n][k];
// }

bool isPowerOfTwo(int x)
{
    /* First x in the below expression is for the case when x is 0 */
    return x && (!(x & (x - 1)));
}

signed main()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
// for writing output to output.txt
// freopen("output.txt", "w", stdout);
#endif

    //fflush(stdout);
    fio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n][m];
        for0(i, n)
        {
            for0(j, m)
            {
                cin >> a[i][j];
            }
        }

        loop(bit, 0, 10)
        {
            int gin = 0;
            int mark = 0;
            for0(i, n)
            {
                int cnt = 0;
                for0(j, m)
                {
                    int num = a[i][j];
                    int x = -1;
                    while (num && x < bit)
                    {
                        x++;
                        if (num & 1 && x == bit)
                        {
                            cnt++;
                        }

                        num >>= 1;
                    }
                }

                if (cnt)
                    gin++;
                if (cnt < m && cnt)
                    mark = 1;
            }

            if (gin % 2)
            {
                cout << "TAK\n";
                for0(i, n)
                {
                    int f = 0;
                    for0(j, m)
                    {
                        int num = a[i][j];
                        int x = -1;
                        while (num && x < bit)
                        {
                            x++;
                            if (num & 1 && x == bit)
                            {
                                cout << j + 1 << " ";
                                f = 1;
                                break;
                            }

                            num >>= 1;
                        }

                        if (f)
                            break;
                    }
                    if (!f)
                        cout << 1 << " ";
                }
                rr;
            }
            else if (mark && gin % 2 == 0 && gin != 0)
            {
                cout << "TAK\n";
                int mark = 0;
                for0(i, n)
                {
                    int f = 0;
                    int cnt = 0;
                    int numm;
                    int xx;
                    for0(j, m)
                    {
                        f = 0;
                        int num = a[i][j];
                        int x = -1;
                        while (num && x < bit)
                        {
                            x++;
                            if (num & 1 && x == bit)
                            {
                                cnt++;
                                xx = j + 1;
                                f = 1;
                            }

                            num >>= 1;
                        }

                        if (!f && !mark)
                            numm = j + 1;
                    }
                    if (!mark && cnt != m && cnt)
                    {
                        cout << numm << " ";
                        mark = 1;
                    }
                    else if (cnt == 0)
                    {
                        cout << 1 << " ";
                    }
                    else
                    {
                        cout << xx << " ";
                    }
                }
                rr;
            }
        }

        cout << "NIE";
    }
    rr;
}