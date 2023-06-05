// ------------Akshat Kothavade----------------
// -----------CC : Akshat123436-----------------

#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define int long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "," << #y << " = " << y << endl
#define PI 3.1415926535897932384626
#define endl '\n'

int mpow(int base, int exp);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

//          ------ LETS START 💫💫💫 -------

void solve()
{
    int n, m;
    cin >> n >> m;
    int correct[n], incorrect[m];
    int max_correct = INT_MIN;
    int min_correct = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        cin >> correct[i];
        if (correct[i] > max_correct)
        {
            max_correct = correct[i];
        }
        if (correct[i] < min_correct)
        {
            min_correct = correct[i];
        }
    }
    int min_incorrect = INT_MAX;

    for (int i = 0; i < m; i++)
    {
        cin >> incorrect[i];
        if (incorrect[i] < min_incorrect)
        {
            min_incorrect = incorrect[i];
        }
    }
    int time = 0;
    if (min_incorrect <= max_correct)
    {
        cout << -1 << endl;
    }
    else
    {
        int minimum_req = 2 * min_correct;

        if (minimum_req > max_correct)
        {
            time = minimum_req;
        }
        else
        {
            time = max_correct;
        }

        if (time >= min_incorrect)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << time << endl;
        }
    }
}

int32_t main()
{
    // ios_base::sync_with_stdio(0), cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((int)result * base) % mod;
        base = ((int)base * base) % mod;
        exp >>= 1;
    }
    return result;
}
