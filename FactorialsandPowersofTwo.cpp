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

vector<int> powers(40);
vector<int> factorials(14);

int calculator(int num, map<int, bool> &factcheck, bool &impossible)
{
    if (num == 1)
    {
        factcheck[1] = true;
        factcheck[1] = true;
        return 1;
    }
    if(num==0) return 0;
    int faco = 0;
    int pawo = 0;
    int temp = upper_bound(factorials.begin(), factorials.end(), num) - factorials.begin();
    temp--;
    while (temp >= 0 && factcheck[factorials[temp]])
    {
        temp--;
    }
    int num1 = 0; num2 = 0;
    if (temp >= 0)
    {
        factcheck[factorials[temp]] = true;
        num1 = factorials[temp];
        faco = 1 + calculator(num - factorials[temp], factcheck, impossible);
        
    }
    temp = upper_bound(powers.begin(), powers.end(), num) - powers.begin();
    temp--;
    while (temp >= 0 && factcheck[powers[temp]])
    {
        temp--;
    }
    if (temp >= 0)
    {
        factcheck[powers[temp]] = true;
        num2 = pwoers[temp];
        pawo = 1 + calculator(num - powers[temp], factcheck, impossible);
    }
    if (faco == 0 && pawo == 0)
        impossible = true;
    debug(num);debug(faco);debug(pawo);
    int minimum = min(faco, pawo);
    if(minimum == faco){
        factcheck
    }
    if(faco == 0) return pawo;

    else if (pawo == 0) {return faco;}
    return min(faco, pawo);
}

int32_t main()
{

    fastio();

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    cin >> t;

    for (int i = 0; i < 40; i++)
    {
        powers[i] = pow(2, i);
    }

    factorials[0] = 1;

    for (int i = 1; i < 15; i++)
    {
        factorials[i] = i * factorials[i - 1];
    }
    auto powerfirst = powers.begin();
    auto factfirst = factorials.begin();
    debug(powers);debug(factorials);
    while (t--)
    {
        bool imPossible = false;
        int n;
        cin >> n;
        map<int, bool> factcheck;
        // map<int, bool> powerCheck;
        int ans = calculator(n, factcheck, imPossible);

        if(imPossible) cout << -1 << endl;
        else{
            cout << ans << endl;
        }
    }
}