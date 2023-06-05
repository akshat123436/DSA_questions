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
char input[1000][1000];
int main()
{

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    cin >> t;

    while (t--)
    {
        int n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> input[i][j];
            }
        }
        int c = 0;
        // if(input[n-2][n] == input[n-1][n-1]){
        //     if(input[n-1][n] == input[n-1][n-1]){
        //         c++;
        //         if(input[n-1][n] == '1')
        //             input[n-1][n] = '0';
        //         else input[n-1][n] = '1';
        //     }
        // }
        // if(input[n][n-2] == input[n-1][n-1]){
        //     if(input[n][n-1] == input[n-1][n-1]){
        //         c++;
        //         if(input[n][n-1] == '1')
        //             input[n][n-1] = '0';
        //         else input[n][n-1] = '1';
        //     }
        // }
        bool threesame = false;
        bool twosame = false;
        vector<pair<int, int>> v;
        if (input[n - 1][n - 1] == input[n - 2][n] && input[n - 1][n - 1] == input[n][n - 2])
            threesame = true;
        if (input[n - 1][n] == input[n][n - 1])
        {
            twosame = true;
        }
        bool ansFound = false;
        if (threesame && twosame)
        {
            if (input[n - 1][n] != input[n - 1][n - 1])
            {
                ansFound = true;
            }
            else
            {
                ansFound = true;
                c = 2;
                v.push_back({n - 1, n});
                v.push_back({n, n - 1});
            }
        }
        else if (threesame)
        {
            ansFound = true;
            if (input[n - 1][n] == input[n - 1][n - 1])
            {
                c = 1;
                v.push_back({n - 1, n});
            }
            else if (input[n][n - 1] == input[n - 1][n - 1])
            {
                c = 1;
                v.push_back({n, n - 1});
            }
        }
        else if (twosame)
        {
            ansFound = true;
            if (input[n - 1][n - 1] == input[n - 1][n])
            {
                c++;
                v.push_back({n - 1, n - 1});
            }
            if (input[n][n - 2] == input[n - 1][n])
            {
                c++;
                v.push_back({n, n - 2});
            }
            if (input[n - 2][n] == input[n - 1][n])
            {
                c++;
                v.push_back({n - 2, n});
            }
        }
        if (!ansFound)
        {
            if (input[n - 2][n] == input[n - 1][n] && input[n][n - 2] == input[n][n - 1])
            {
                if (input[n - 1][n - 1] == input[n - 1][n])
                {
                    c+=2;
                    v.push_back({n - 1, n});
                    v.push_back({n, n - 2});
                }
                else
                {

                    c+=2;
                    v.push_back({n, n - 1});
                    v.push_back({n - 2, n});
                }
            }
            else if(input[n - 2][n] == input[n - 1][n] || input[n][n - 2] == input[n][n - 1]){
                if (input[n - 1][n - 1] == input[n][n-1])
                {
                    c+=2;
                    v.push_back({n, n-1});
                    v.push_back({n, n - 2});
                }
                else{
                    c+=2;
                    v.push_back({n-1, n});
                    v.push_back({n-2, n});
                }
            }
        }
    }
}