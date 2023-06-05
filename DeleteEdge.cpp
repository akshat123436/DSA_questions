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
int total;
class Solution
{
    int deleteEdge(vector<int> &A, vector<vector<int>> &B);
};

void dfs(vector<vector<int>> &tree, int vertex, vector<int> &A, vi &sum, int parent = -1)
{
    int ss = A[vertex - 1];

    for (auto a : tree[vertex])
    {
        if (vertex != parent)
        {
            dfs(tree, a, A, sum, vertex);
            ss += sum[a];
        }
    }
    sum[vertex] = ss;
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int>> &B)
{

    for (auto a : A)
    {
        total += a;
    }

    vector<vi> tree(A.size() + 1);

    for (auto a : B)
    {
        tree[a[0]].push_back(a[1]);
        tree[a[1]].pb(a[0]);
    }

    vi sum(A.size() + 1);

    dfs(tree, 1, A, sum);

    int mul = INT_MIN;

    for (auto a : B)
    {
        int tt = min(sum[a[0]], sum[a[1]]);
        tt *= total - tt;
        if (tt > mul)
            mul = tt;
    }
    return mul%(10^9 + 7);
}

void solve()
{
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