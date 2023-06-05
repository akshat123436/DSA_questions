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

vi graph[100000];
bool isVisited[100000];
queue<int> q;
void bfs(int vertex)
{
    // cout << "here ";
    if (!isVisited[vertex])
        q.push(vertex);
    isVisited[vertex] = true;

    for (auto a : graph[vertex])
    {
        if (isVisited[a])
            continue;
        q.push(a);
        isVisited[a] = true;
    }
    if (q.empty())
        return;
    cout << q.front() << " ";
    q.pop();
    if (q.empty())
        return;
    bfs(q.front());
}

void solve()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    bfs(1);
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