#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
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
#define int long long

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

void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
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
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
bool cmp(int a, int b)
{
    return a > b;
}
bool accumulator(int a, int b)
{
    return a + b;
}
// Function to find the value of
// P * Q^-1 mod 998244353
long long calculate(long long p, long long q)
{
    long long mod = 998244353, expo;
    expo = mod - 2;
    // Loop to find the value
    // until the expo is not zero
    while (expo)
    {
        // Multiply p with q
        // if expo is odd
        if (expo & 1)
        {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
        // Reduce the value of
        // expo by 2
        expo >>= 1;
    }
    return p;
}

int32_t main()
{

    fastio();

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    cin >> t;

    while (t--)
    {
        map<char, vector<int>> values;
        map<char, int> edges;

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        if (k != 0)
        {
            char temp = s[0];
            int count = 0;
            int first = 0;
            // map <char,bool> checker;
            for (int i = 0; i < n; i++)
            {
                // checker[s[i]] = true;
                if (s[i] != temp)
                {
                    break;
                }
                edges[temp]++;
                first++;
            }
            temp = s[n - 1];
            int second = 0;
            for (int i = n - 1; i >= 0 && first != n; i--)
            {
                if (s[i] != temp)
                    break;
                edges[temp]++;
                second++;
            }
            char check = s[first];
            for(int i = 0;i<s.size();i++){
                vector <int> temp;
                values[s[i]] = temp;
            }
            for (int i = first; i < n - second + 1; i++)
            {
                if (s[i] != check)
                {
                    values[check].push_back(count);
                    count = 0;
                    check = s[i];
                }
                count++;
            }

            for (auto a : values)
            {
                sort(a.second.begin(), a.second.end(), cmp);
            }

            int ans = INT_MIN;

            for (auto a : values)
            {
                int temp = 0;
                for (int i = 0; i < k - 1 && i < a.second.size(); i++)
                {
                    temp += a.second[i];
                }
                temp += edges[a.first];
                if (temp > ans)
                    ans = temp;
            }
            debug(edges);debug(values);debug(first);debug(second);
            cout << ans << endl;
        }

        else
        {
            bool same = true;
            char temp = s[0];
            for (int i = 0; i < s.size(); i++)
            {
                if (temp != s[i])
                {
                    same = false;
                    break;
                }
            }
            if (same)
                cout << s.length();
            else
                cout << -1;
            cout << endl;
        }
    }
}