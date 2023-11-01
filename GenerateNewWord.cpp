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
void sorter(string &s, map<int, char> &order)
{
    unordered_map<char, int> count;
    string temp;
    for (auto a : s)
        count[a]++;

    for (auto &a : order)
    {
        // cout << a.first << " " << a.second << endl;
        int t = count[a.second];
        while (t)
        {
            temp.push_back(a.second);
            t--;
        }
    }
    // cout << temp << endl;
    s = temp;
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
        string dict, inputString;
        getline(cin, dict);
        getline(cin, inputString);
        transform(dict.begin(), dict.end(), dict.begin(), ::tolower);
        transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
        map<int, char> order;
        int index = 1;
        bool check = false;
        unordered_map<char, bool> isPresent;
        for (auto a : dict)
        {
            // cout << order[index] << endl;
            if (isPresent[a])
            {
                check = true;
                break;
            }
            order[index] = a;
            index++;
            isPresent[a] = true;
        }
        vector<string> ans;
        if (check)
            cout << "New language Error" << endl;
        else
        {
            string temp;

            for (auto a : inputString)
            {
                if (a == ' ')
                {
                    // cout << temp << endl;
                    sorter(temp, order);
                    ans.push_back(temp);
                    temp = "";
                }
                else
                {
                    if (isPresent[a])
                        temp.push_back(a);
                }
            }

            if (temp != "")
            {
                // cout << temp << endl;
                sorter(temp, order);
                ans.push_back(temp);
                temp = "";
            }
            for (auto &a : ans)
            {
                cout << a << " ";
            }
            cout << endl;
        }
    }
}