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

// #include <bits/stdc++.h>
// using namespace std;

// #define int long long
// #define endl '\n'
// #define mp(x, y) make_pair(x, y)
// #define vi vector<int>
// #define vl vector<long long>
// #define pb push_back
// #define gcd(a, b) __gcd(a, b)
// #define all(a) a.begin(), a.end()
// #define sz size()
// #define MAX 1000004
// #define MOD 1000000009
// #define um unordered_map
// #define MOD1 998244353

// int graph[100001][100001];
vector<pair<int, int>> graph[100001];
// int weight[100001][100001];
// map<pair<int, int>, int> weight;
// vector<vi> weight(100001, vi(100001));
bool isVisited[100001];
int ans = 0;
int level[100001];
queue<int> q;
void bfs(int start, int end)
{
    // cout << "bfs" << start << " " << level[start] << endl;
    queue<int> temp;
    for (auto a : graph[start])
    {
        if (!isVisited[a.first] || level[start]<level[a.first])
        {
            isVisited[a.first] = 1;
            if (a.second)
            {
                temp.push(a.first);
                level[a.first] = level[start];
            }
            else
            {
                q.push(a.first);
                level[a.first] = level[start] + 1;
            }
        }
    }
    if (!q.empty())
        q.pop();
    while (!q.empty())
    {
        temp.push(q.front());
        q.pop();
    }
    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }
    if (!q.empty())
        bfs(q.front(), end);
}

// void solve()
// {
//     int n, m;
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int v1, v2;
//         cin >> v1 >> v2;
//         // graph[v1][v2] = 1;
//         graph[v1].pb({v2, 1});
//         bool flag = true;

//         for (auto a : graph[v2])
//         {
//             if (a.first == v1)
//             {
//                 if (a.second == 1)
//                 {
//                     flag = false;
//                     break;
//                 }
//             }
//         }
//         if (flag)
//             graph[v2].pb({v1, 0});
//         weight[{v1, v2}] = 1;
//     }
//     // cout << "here" << endl;

//     q.push(1);
//     isVisited[1] = 1;
//     bfs(1, n);
//     // cout << "here" << endl;

//     if (!isVisited[n])
//     {
//         cout << -1 << endl;
//     }
//     else
//     {
//         ans = level[n];
//         cout << ans << endl;
//     }
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t = 1;
//     // cin >> t;
//     while (t--)
//     {
//         solve();
//         debug(graph);
//     }
// }

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
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            // graph[v1][v2] = 1;
            graph[v1].pb({v2, 1});
            bool flag = true;

            for (auto a : graph[v2])
            {
                if (a.first == v1)
                {
                    if (a.second == 1)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
                graph[v2].pb({v1, 0});
            // weight[{v1, v2}] = 1;
        }
        // cout << "here" << endl;

        q.push(1);
        isVisited[1] = 1;
        bfs(1, n);
        // cout << "here" << endl;

        if (!isVisited[n])
        {
            cout << -1 << endl;
        }
        else
        {
            ans = level[n];
            cout << ans << endl;
        }
        // for(int i = 0;i<=8;i++){
        //     debug(graph[i]);
        //     // endl;
        //     // for(auto a : graph)
        // }
        
    }
}