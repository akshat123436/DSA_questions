

/*------------------Instant success builds ego, long term success builds character.---------------*/

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
// C++ function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
int modInverse(int b, int m)
{
    int x, y; // used in extended GCD algorithm
    int g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x % m + m) % m;
}

// Function to compute a/b under modulo m
void modDivide(int a, int b, int m)
{
    a = a % m;
    int inv = modInverse(b, m);
    if (inv == -1)
        cout << "Division not defined";
    else
        cout << "Result of division is " << (inv * a) % m;
}

// C function for extended Euclidean Algorithm (used to
// find modular inverse.
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// to find (a ^ b) with modulo m
int power(int a, int b, int m)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ((a % m) * (ans % m)) % m;
            b--;
        }
        else
        {
            a = ((a % m) * (a % m)) % m;
            b >>= 1;
        }
    }
    return ans;
}

// to hash a string
int h(string &s)
{
    int val = 0;

    for (int i = 0; i < s.length(); i++)
    {
        val = (val * 31 + (s[i] - 'a' + 1)) % MOD;
    }

    return val;
}

// segment tree
int construct(int *st, int start, int end, int i, int *arr)
{
    if (start >= end)
        return st[i] = arr[start];

    int mid = (start + end) / 2;
    return st[i] = min(construct(st, start, mid, 2 * i + 1, arr), construct(st, mid + 1, end, 2 * i + 2, arr));
}

int *constructST(int arr[], int n)
{
    int *st = new int[4 * n];

    construct(st, 0, n - 1, 0, arr);

    return st;
}

int f(int st[], int s, int e, int rs, int re, int i)
{
    if (s >= rs && e <= re)
        return st[i];
    if ((e >= rs && e <= re) || (s >= rs && s <= re) || (rs >= s && re <= e))
    {
        return min(f(st, s, (s + e) / 2, rs, re, 2 * i + 1), f(st, (s + e) / 2 + 1, e, rs, re, 2 * i + 2));
    }

    return INT_MAX;

    // to use : return f(st, 0, n-1, a, b, 0); (finds smallest in the range a, b : 0-based indexing);
}

int32_t main()
{
    // fastio();
#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> first(n), second(n);
        
        for(int i = 0;i<n;i++){
            string temp;
            cin >> temp;
            first[i] = temp;
        }
        for(int i = 0;i<n;i++){
            string temp;
            cin >> temp;
            second[i] = temp;
        }
        
        for(int i=  0;i<n-1;i++){
            for(int j = 0;j<m-1;j++){
                if(first[i][j]!=second[i][j]){
                    int diff = second[i][j] - first[i][j];
                    
                    if(diff==1 || diff == -2){
                        first[i][j] += 1;
                        first[i+1][j] += 2;
                        first[i][j+1] += 2;
                        first[i+1][j+1] += 1;
                        
                    }
                    else{
                        first[i][j] += 2;
                        first[i+1][j] += 1;
                        first[i][j+1] += 1;
                        first[i+1][j+1] += 2;
                    }
                    first[i][j] = ((first[i][j]-'0') % 3) + '0';
                    first[i+1][j] = ((first[i+1][j]-'0') % 3) + '0';
                    first[i][j+1] = ((first[i][j+1]-'0') % 3) + '0';
                    first[i+1][j+1] = ((first[i+1][j+1]-'0') % 3) + '0';
                }
            }
        }
        bool check = true;
            for(int i = 0;i<n;i++){
                for(int j= 0;j<m;j++){
                    if(first[i][j] != second[i][j]) check = false;
                }
            }
            if(check) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }