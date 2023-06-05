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
#define maxi (int)(1e7 + 10)
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

void _print(ll t)
{
    cerr << t;
}
// void _print(int t) {cerr << t;}
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

//---------------------------------------------------------------------------------------------------------------------------------------

bool cmp(int a, int b)
{
    return a < b;
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

    // fastio();

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    // cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        // cout << s << endl;
        stack<pair<char, int>> temp;
        map<int, int> count2, count;
        // cout << 1 << endl;
        for (int i = 0; i < s.size(); i++)
        {

            // debug(temp.top().first);
            // cout << 1 << endl;
            if (!temp.empty())
            {
                // cout << "i " << i << endl;
                if (s[i] == ')')
                {
                    // cout << temp.top().first << endl;
                    if ((temp.top()).first == '(')
                    {
                        // cout << "akshat" << endl;
                        count[(i - temp.top().second) + 1]++;
                        count2[i] += i - temp.top().second + 1;
                        if (temp.top().second > 0)
                        {
                            if (s[temp.top().second - 1] == ')')
                            {
                                count2[i] += count2[temp.top().second - 1];
                                if (count2[temp.top().second - 1])
                                    count[count2[i]]++;
                            }
                        }
                        temp.pop();
                    }
                    else
                        temp.push(make_pair(s[i], i));
                }
                else
                    temp.push(make_pair(s[i], i));
            }
            else
                temp.push({s[i], i});
        }
        debug(count);
        debug(count2);
        bool isPossible = false;
        int max = INT_MIN;
        int county = 0;
        for (auto a : count)
        {
            if (a.second > 0)
            {
                if (a.first > max)
                {
                    max = a.first;
                    county = a.second;
                }
            }
        }
        if (county)
            cout << max << " " << county << endl;
        else
            cout << "0 1" << endl;
    }
}

// ()()((()))