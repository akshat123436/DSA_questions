#include <bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
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
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

int main() {

    #ifndef ONLINE_JUDGE

        freopen("Error.txt", "w", stderr);

    #endif

    int t=1;

    cin >> t;

    while(t--){
        ll k, x;
        cin >> k >> x;

        ll increasing = k*(k-1)/2;

        ll decreasing = k*(k+1)/2;

        ll total = increasing + decreasing;
        debug(increasing);debug(decreasing);debug(total);
        if(x >= total){
            // cout << 1 << "---------" << endl;
            cout << 2 * k -1 << endl;
        }
        else if(x > increasing){
            // cout << 2 << "---------" << endl;

            ll terms = k-1;
            long double temp = (2 * k + 1)/2.0;
            ll sum = x - increasing;
            ll n = ceill(temp - sqrtl(temp * temp  - 2 * sum));
            debug(n);debug(temp);debug(sum);
            if(n > 0){
                terms += n;
            }
            cout << terms << endl;
        }
        else{
            // cout << 3 << "---------" << endl;
            long double temp = 8 * x + 1;
            ll n = ceill((sqrtl(temp) - 1)/2);
            cout << n << endl;
        }
    }

}