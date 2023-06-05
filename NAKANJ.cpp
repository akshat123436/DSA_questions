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

int num = 1;
void bfs(int &ans, string start, string end, int &temp, queue<string> &q,
         map<string, bool> &isVisited,
         vector<string> &ending)
{
    char s1, s2, e1, e2;
    s1 = start[0];
    s2 = start[1];
    e1 = end[0];
    e2 = end[1];

    if (start == end)
    {
        ans = temp;
        return;
    }
    string tt;
    tt += s1 + 1;
    tt += s2 + 2;
    if (s1 + 1 <= 'h' && s2 + 2 <= '8' && !isVisited[tt])
    {
        isVisited[tt] = true;
        q.push(tt);
        ending[num] = tt;
    }
    tt = "";
    tt += s1 + 2;
    tt += s2 + 1;
    if (s1 + 2 <= 'h' && s2 + 1 <= '8' && !isVisited[tt])
    {
        isVisited[tt] = true;
        ending[num] = tt;
        q.push(tt);
    }
    tt = "";
    tt += s1 + 2;
    tt += s2 - 1;
    if (s1 + 2 <= 'h' && s2 - 1 >= '1' && !isVisited[tt])
    {
        isVisited[tt] = true;
        ending[num] = tt;
        q.push(tt);
    }
    tt = "";
    tt += s1 - 2;
    tt += s2 - 1;
    if (s1 - 2 >= 'a' && s2 - 1 >= '1' && !isVisited[tt])
    {
        isVisited[tt] = true;
        ending[num] = tt;
        q.push(tt);
    }
    tt = "";
    tt += s1 - 2;
    tt += s2 + 1;
    if (s1 - 2 >= 'a' && s2 + 1 <= '8' && !isVisited[tt])
    {
        isVisited[tt] = true;
        ending[num] = tt;
        q.push(tt);
    }
    tt = "";
    tt += s1 - 1;
    tt += s2 + 2;
    if (s1 - 1 >= 'a' && s2 + 2 <= '8' && !isVisited[tt])
    {
        isVisited[tt] = true;
        ending[num] = tt;
        q.push(tt);
    }
    tt = "";
    tt += s1 + 1;
    tt += s2 - 2;
    if (s1 + 1 <= 'h' && s2 - 2 >= '1' && !isVisited[tt])
    {
        isVisited[tt] = true;
        ending[num] = tt;
        q.push(tt);
    }
    tt = "";
    tt += s1 - 1;
    tt += s2 - 2;
    if (s1 - 1 >= 'a' && s2 - 2 >= '1' && !isVisited[tt])
    {
        isVisited[tt] = true;
        ending[num] = tt;
        q.push(tt);
    }

    if (start == ending[num - 1])
    {
        temp++;
        num++;
    }
    q.pop();
    bfs(ans, q.front(), end, temp, q, isVisited, ending);
}

void solve()
{
    num = 1;
    string start, end;
    cin >> start >> end;
    queue<string> q;
    vector<string> ending(100000);
    map<string, bool> isVisited;
    int ans = 0;
    q.push(start);
    ending[0] = start;
    isVisited[start] = true;
    int tt = 0;

    bfs(ans, start, end, tt, q, isVisited, ending);
    // for (int i = 0; i < 4; i++)
    //     cout << ending[i] << endl;
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}