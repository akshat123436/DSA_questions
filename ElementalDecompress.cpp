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

void _print(ll t) {cerr << t;}
//void _print(int t) {cerr << t;}
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

    fastio();

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n], brr[n];
        set<int> sorted;
        for (int i = 0; i < n; i++)
        {
            sorted.insert(i + 1);
        }

        map<int, int> count;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            brr[i] = arr[i];
        }
        bool notPossible = false;

        map<int, stack<int>> values;

        sort(arr, arr + n);
        vector<int> a, b;
        map<int, int> aa, bb;
        for (int i = 0; i < n && sorted.size(); i++)
        {
            if (count[arr[i]] < 2)
            {
                count[arr[i]]++;
                if (count[*(sorted.begin())] < 2)
                {
                    count[*(sorted.begin())]++;
                    values[arr[i]].push(*(sorted.begin()));
                }
                else
                {
                    notPossible = true;
                    break;
                }
            }
            else
            {
                notPossible = true;
                break;
            }
            if (notPossible)
                break;
            while (sorted.size() && count[*(sorted.begin())] >= 2)
            {
                sorted.erase(sorted.begin());
            }
        }
        for(auto a : values){
            cout << a.first << endl;
            while(a.second.size()){
                cout << a.second.top() << " ";
                a.second.pop();
            }cout << endl;
        }
        if (notPossible)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                debug(a);debug(b);
                cout << "i " << i << endl;
                if (!aa[brr[i]])
                {
                    bool check = false;
                    stack<int> temp = values[values[brr[i]].top()];
                    while (temp.size())
                    {
                        if (bb[temp.top()])
                        {
                            check = true;
                            break;
                        }
                        temp.pop();
                    }
                    if (check)
                    {
                        cout << 0 << endl;
                        bb[brr[i]] = 1;
                        b.push_back(brr[i]);
                        a.push_back(values[brr[i]].top());
                        values[brr[i]].pop();
                    }
                    else
                    {
                        cout << 1 << endl;
                        aa[brr[i]] = 1;
                        a.push_back(brr[i]);
                        b.push_back(values[brr[i]].top());
                        values[brr[i]].pop();
                    }
                }
                else
                {
                    cout << 2 << endl;
                    bb[brr[i]] = 1;
                    b.push_back(brr[i]);
                    a.push_back(values[brr[i]].top());
                    values[brr[i]].pop();
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}