#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define mp(x, y) make_pair(x, y)
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define gcd(a, b) __gcd(a, b)
#define all(a) a.begin(), a.end()
#define sz size()
#define MAX 1000004
#define MOD 1000000009
#define um unordered_map
#define MOD1 998244353

vector<vi> tree(100000);
int sum[100000];
int even_count[100000];
void dfs(int vertex, int parent = 0)
{
    int summ = vertex;
    int count = !(vertex % 2);
    // cout << count << endl;
    for (auto a : tree[vertex])
    {
        if (a != parent)
        {
            dfs(a, vertex);
            summ += sum[a];
            count += even_count[a];
        }
    }
    sum[vertex] = summ;
    even_count[vertex] = count;
}

void solve()
{
    int n, e;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        tree[v1].pb(v2);
        tree[v2].pb(v1);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        cout << sum[i] << " " << even_count[i] << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}