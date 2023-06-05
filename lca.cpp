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
int parent[100000];

void dfs(int vertex, int parentt = 0)
{
    for (auto a : tree[vertex])
    {
        if (a != parentt)
        {
            parent[a] = vertex;
            dfs(a, vertex);
        }
    }
}

int lca(int v1, int v2)
{
    // cout << "lca" << endl;
    vi one_parents, two_parents;
    one_parents.pb(v1);
    while (v1)
    {
        one_parents.pb(parent[v1]);
        v1 = parent[v1];
        if (!parent[v1])
            break;
    }

    two_parents.pb(v2);
    while (v2)
    {
        two_parents.pb(parent[v2]);
        v2 = parent[v2];
        if (!parent[v2])
            break;
    }
    reverse(one_parents.begin(), one_parents.end());
    reverse(two_parents.begin(), two_parents.end());
    int i = 0;
    int ans = 0;
    while (one_parents[i] == two_parents[i])
    {
        ans = one_parents[i];
        i++;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    dfs(1);

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << parent[i] << endl;
    // }
    cout << lca(9, 11) << endl;
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
// 13
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 5 6
// 5 7
// 5 8
// 8 12
// 4 9
// 4 10
// 10 11