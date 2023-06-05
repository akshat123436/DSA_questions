#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
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
#define maxi (int)(1e4 + 10)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)       \
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

ll adder[maxi][maxi];
ll arr[maxi][maxi];
int main()
{

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    // cin >> t;

    while (t--)
    {
        int n, m, u, q;
        cin >> n >> m >> u >> q;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int k = 0; k < u; k++)
        {
            int temp, r1, c1, r2, c2;

            cin >> temp >> r1 >> c1 >> r2 >> c2;

            adder[r1 + 1][c1 + 1] += temp;
            adder[r2 + 1 + 1][c2 + 1 + 1] += temp;
            adder[r1 + 1][c2 + 1 + 1] -= temp;
            adder[r2 + 1 + 1][c1 + 1] -= temp;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                adder[i][j] += adder[i - 1][j] + adder[i][j - 1] - adder[i - 1][j - 1];
            }
        }

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         cout << adder[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                arr[i][j] += adder[i][j];
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < q; i++)
        {
            int r1, c1, r2, c2;

            cin >> r1 >> c1 >> r2 >> c2;

            ll ans = arr[r2+1][c2+1] - arr[r1 - 1 + 1][c2+1] - arr[r2+1][c1 - 1 +1] + arr[r1 - 1 + 1][c1 - 1 + 1];

            cout << ans << endl;
        }
    }
}