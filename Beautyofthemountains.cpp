

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

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
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
int allGcd(vector<int> &nums){
    int curGcd = abs(nums[0]);
    for(auto &a : nums){
        curGcd = __gcd(curGcd, abs(a));
    }
    return curGcd;
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
        // debug(t);
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> mat(n, vector<int> (m));
        for(int i = 0;i<n;i++) for(int j = 0;j<m;j++) cin >> mat[i][j];
            vector<string> temp(n);
        for(int i =0;i<n;i++){
            cin >> temp[i];
        }
        vector<vector<int>> mountains(n, vector<int> (m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                mountains[i][j] = temp[i][j] - '0';
            }
        }
        // debug(mountains);
        for(int j = 0;j<m;j++){
            for(int i = 1;i<n;i++){
                mountains[i][j] += mountains[i-1][j];
            }
            
        }
        // debug(mountains);
        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                mountains[i][j] += mountains[i][j-1];
            }
        }
        // debug(mountains);
        int initialDifference = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(temp[i][j] == '1'){
                    initialDifference += mat[i][j];
                }
                else{
                    initialDifference -= mat[i][j];
                }
            }
        }
        // debug(initialDifference);
        if(initialDifference == 0){
            cout << "YES" << endl;
            continue;
        }
        vector<int> differences;
        for(int i = k-1;i<n;i++){
            for(int j = k-1;j<m;j++){
                int top = 0, left = 0, corner = 0;
                if(i - (k-1) > 0){
                    top = mountains[i-(k-1) - 1][j];
                }
                if(j - (k - 1) > 0){
                    left = mountains[i][j-(k-1)-1];
                }
                if((i - (k - 1)) > 0 && (j - (k-1)) > 0){
                    corner = mountains[i-(k-1)-1][j-(k-1)-1];
                }
                int finalOnes = mountains[i][j] - top - left + corner;
                // debug(i); debug(j);debug(mountains[i][j]); debug(top); debug(left); debug(corner);
                differences.push_back(finalOnes - ((k * k) - finalOnes));
            }
        }
        // debug(differences);
        bool allzero = true;
        for(auto &a : differences) if(a) allzero = false;
        
        if(allzero){
            cout << "NO" << endl;
            continue;
        }
        
        if(initialDifference % allGcd(differences) == 0){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}