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
    return b < a;
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

bool checker(int mid, vector <int> bikes, vector <int> boys, int a){
    if(boys.size() >= mid+1){
        int required = 0;
        for(int i = 0, j = mid;i<=mid;i++,j--){
            if(!(boys[i] >= bikes[j])) required += bikes[j] - boys[i];
        }
        if(required > a) return false;
        return true;
    }
    else return false;
}

int searcher(vector <int> &bikes,int low, int high, vector <int> &boys, int a){
    while(high - low >= 2){
        int mid = (low + high)/2;
        debug(low);
        debug(mid);
        debug(high);
        if(checker(mid, bikes, boys,a)){
            low = mid;
        }
        else{
            high = mid-1;
        }
    }
    if(checker(high, bikes, boys,a)) return high;
    if(checker(low, bikes, boys,a)) return low;
    return -1;
}

int32_t main()
{

    fastio();

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    // cin >> t;

    while (t--)
    {
        int n, m, a;
        cin >> n >> m >> a;

        vector <int> boys(n), bikes(m), bikers(m);

        for(int i = 0;i<n;i++){
            cin >> boys[i];
        }

        for(int j = 0;j<m;j++){
            cin >> bikes[j];
            // bikers[j] = bikes[j];
        }

        sort(boys.begin(), boys.end(), cmp);
        sort(bikes.begin(), bikes.end());
        for(int j = 0;j<m;j++){
            bikers[j] = bikes[j];
        }
        // for(int i = 1;i<n;i++){
        //     boys[i] += boys[i-1];
        // }

        for(int i = 1;i<m;i++){
            bikers[i] += bikers[i-1];
        }
        // int num = 0, budget = 0;
        // for(int i = 0;i<n;i++){
        //     int val = 0;
        //     if(bikes[i] > a) val = bikes[i] - a;
        //     if(boys[i] >= val){
        //         num = i+1;
        //         budget = val;
        //     }
        // }

        int num = searcher(bikes, 0, m-1, boys,a);

        int budget = max(ll(0),bikers[num]-a);
        if(num == -1) budget = 0;
        cout << num+1 << " " << budget << endl;
    }
}