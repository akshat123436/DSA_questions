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

void solve()
{
    int n;
    cin >> n;

    int arr[2 * n];

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + 2 * n);
    bool flag = true;
    int sum = arr[0] + arr[2 * n - 1];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + arr[2 * n - i - 1] != sum)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "PERFECT" << endl;
    }
    else
    {
        cout << "IMBALANCED" << endl;
    }
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