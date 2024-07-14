

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
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];

            if (i)
                a[i] += a[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];

            if (i)
                b[i] += b[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> c[i];

            if (i)
                c[i] += c[i - 1];
        }

        vector<int> sia, sib, sic;
        map<int, int> lia, lib, lic;

        int left = 0, right = 0;
        int req = ceil(a[n - 1] / 3.0);
        while (left < n && right < n)
        {
            int sum = a[right];

            if (left)
                sum -= a[left - 1];
            
            while (left < right && (a[right] - a[left] >= req))
            {
                left++;
            }
            if(sum < req){
                right++;
                continue;
            }
            sia.push_back(left);
            lia[left] = right;
            right++;
            left++;
        }

        left = 0, right = 0;
        while (left < n && right < n)
        {
            int sum = b[right];

            if (left)
                sum -= b[left - 1];

            while (left < right && (b[right] - b[left] >= req))
            {
                left++;
            }
            if(sum < req){
                right++;
                continue;
            }
            sib.push_back(left);
            lib[left] = right;
            right++;
            left++;
        }

        left = 0, right = 0;
        while (left < n && right < n)
        {
            int sum = c[right];

            if (left)
                sum -= c[left - 1];

            while (left < right && (c[right] - c[left] >= req))
            {
                left++;
            }
            if(sum < req){
                right++;
                continue;
            }
            sic.push_back(left);
            lic[left] = right;
            right++;
            left++;
        }

        vector<int> ans(6);
        bool found = false;
        // for(auto &k : sia){
        //     cout << k << " " << lia[k];
        //     cout << endl;
        // }
        // cout << endl;
        // for(auto &k : sib){
        //     cout << k << " " << lib[k];
        //     cout << endl;
        // }
        // cout << endl;
        // for(auto &k : sic){
        //     cout << k << " " << lic[k];
        //     cout << endl;
        // }
        // cout << endl;
        for (auto &s : sia)
        {
            int astart = s, aend = lia[s];

            auto ptr = upper_bound(sib.begin(), sib.end(), aend) - sib.begin();

            if (ptr != sib.size())
            {
                int bstart = sib[ptr], bend = lib[bstart];

                ptr = upper_bound(sic.begin(), sic.end(), bend) - sic.begin();

                if (ptr != sic.size())
                {
                    int cstart = sic[ptr], cend = lic[cstart];

                    ans = {astart + 1, aend + 1, bstart + 1, bend + 1, cstart + 1, cend + 1};
                    found = true;
                }
            }

            if (!found)
            {
                ptr = upper_bound(sic.begin(), sic.end(), aend) - sic.begin();
                if (ptr != sic.size())
                {
                    int cstart = sic[ptr], cend = lic[cstart];

                    ptr = upper_bound(sib.begin(), sib.end(), cend) - sib.begin();

                    if (ptr != sib.size())
                    {
                        int bstart = sib[ptr], bend = lib[bstart];

                        ans = {astart + 1, aend + 1, bstart + 1, bend + 1, cstart + 1, cend + 1};
                        found = true;
                    }
                }
            }

            if (found)
                break;
        }
        if (!found)
            for (auto &s : sib)
            {
                int bstart = s, bend = lib[s];

                auto ptr = upper_bound(sia.begin(), sia.end(), bend) - sia.begin();

                if (ptr != sia.size())
                {
                    int astart = sia[ptr], aend = lia[astart];

                    ptr = upper_bound(sic.begin(), sic.end(), aend) - sic.begin();

                    if (ptr != sic.size())
                    {
                        int cstart = sic[ptr], cend = lic[cstart];

                        ans = {astart + 1, aend + 1, bstart + 1, bend + 1, cstart + 1, cend + 1};
                        found = true;
                    }
                }

                if (!found)
                {
                    ptr = upper_bound(sic.begin(), sic.end(), bend) - sic.begin();
                    if (ptr != sic.size())
                    {
                        int cstart = sic[ptr], cend = lic[cstart];

                        ptr = upper_bound(sia.begin(), sia.end(), cend) - sia.begin();

                        if (ptr != sia.size())
                        {
                            int astart = sia[ptr], aend = lia[astart];

                            ans = {astart + 1, aend + 1, bstart + 1, bend + 1, cstart + 1, cend + 1};
                            found = true;
                        }
                    }
                }

                if (found)
                    break;
            }
        if (!found)
            for (auto &s : sic)
            {
                int cstart = s, cend = lic[s];

                auto ptr = upper_bound(sib.begin(), sib.end(), cend) - sib.begin();

                if (ptr != sib.size())
                {
                    int bstart = sib[ptr], bend = lib[bstart];

                    ptr = upper_bound(sia.begin(), sia.end(), bend) - sia.begin();

                    if (ptr != sia.size())
                    {
                        int astart = sia[ptr], aend = lia[astart];

                        ans = {astart + 1, aend + 1, bstart + 1, bend + 1, cstart + 1, cend + 1};
                        found = true;
                    }
                }

                if (!found)
                {
                    ptr = upper_bound(sia.begin(), sia.end(), cend) - sia.begin();
                    if (ptr != sia.size())
                    {
                        int astart = sia[ptr], aend = lia[astart];

                        ptr = upper_bound(sib.begin(), sib.end(), aend) - sib.begin();

                        if (ptr != sib.size())
                        {
                            int bstart = sib[ptr], bend = lib[bstart];

                            ans = {astart + 1, aend + 1, bstart + 1, bend + 1, cstart + 1, cend + 1};
                            found = true;
                        }
                    }
                }

                if (found)
                    break;
            }
            
            if(found){
                for(auto &k : ans) cout << k << " ";
                    cout << endl;
            }
            else cout << -1 << endl;
    }
}