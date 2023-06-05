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
#define maxi 1e7 + 10;

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

int main()
{

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> m;
        n = m;
        m *= 2;
        map<int, int> count;
        int arr[n];
        int temp[m];
        for (int i = 0; i < m; i++)
        {
            cin >> temp[i];
            count[temp[i]]++;
        }

        int l = 0;
        if (count.size() == n)
        {
            for (auto a : count)
            {
                arr[l] = a.first;
                l++;
            }
            sort(arr, arr + n);
            bool impossible = false;
            if (count[arr[n - 1]] == 1)
            {
                if (n % 2 == 0)
                {
                    for (int i = 0; i < n / 2 - 1; i++)
                    {
                        if (count[arr[i]] != 2)
                        {
                            impossible = true;
                            break;
                        }
                    }
                    if (count[arr[n / 2 - 1]] != 3)
                    {
                        impossible = true;
                        break;
                    }
                    for (int i = n - 2; i >= n / 2; i--)
                    {
                        if (count[arr[i]] != 2)
                        {
                            impossible = true;
                            break;
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < n / 2; i++)
                    {
                        if (count[arr[i]] != 2)
                        {
                            impossible = true;
                            break;
                        }
                    }
                    if (count[arr[n / 2]] != 3)
                    {
                        impossible = true;
                        break;
                    }
                    for (int i = n - 2; i > n / 2; i--)
                    {
                        if (count[arr[i]] != 2)
                        {
                            impossible = true;
                            break;
                        }
                    }
                }
            }
            else
            {
                impossible = true;
            }
            if (count.size() == 1 && n == 1)
            {
                for (auto a : count)
                {
                    cout << a.first << " ";
                }
                cout << endl;
            }
            else if (impossible)
            {
                cout << -1 << endl;
            }
            else
            {
                for (auto a : count)
                {
                    cout << a.first << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
}