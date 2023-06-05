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
        int n, T;
        cin >> n >> T;

        int given[n];
        int output[n];
        map<int, vector<int>> indexes;
        for (int i = 0; i < n; i++)
        {
            cin >> given[i];
            indexes[given[i]].push_back(i);
        }
        sort(given, given + n);
        map<int, bool> isDone;
        for (int i = 0; i < n; i++)
        {
            if (!isDone[given[i]])
            {
                isDone[given[i]] = true;
                isDone[T-given[i]] = true;
                if (T - given[i] > given[i])
                {
                    for (auto a : indexes[T - given[i]])
                    {
                        output[a] = 1;
                    }
                    for (auto a : indexes[given[i]])
                    {
                        output[a] = 0;
                    }
                }
                else if (T - given[i] == given[i])
                {
                    // int count = 0;
                    // for (auto a : indexes[T - given[i]])
                    // {
                    //     output[a] = 1;
                    //     count++;
                    //     if (count >= 1)
                    //         break;
                    // }
                    // for (auto a : indexes[given[i]])
                    // {
                    //     if (count != 1)
                    //         output[a] = 0;
                    //     count++;
                    // }
                    int size = (indexes[given[i]]).size();
                    // cout << size << " size \n";
                    for (int j = 0; j < size / 2; j++)
                    {
                        output[(indexes[given[i]])[j]] = 0;
                    }
                    for (int j = size / 2; j < size; j++)
                    {
                        output[indexes[given[i]][j]] = 1;
                    }
                }
                else
                {
                    for (auto a : indexes[given[i]])
                    {
                        output[a] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
    }
}