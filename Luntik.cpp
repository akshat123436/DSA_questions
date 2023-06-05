// Author : Akshat Kothavade
// CC : Akshat123436

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
int mpow(int base, int exp);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;

//          ------ LETS START 💫💫💫 -------

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int left = {}, right = {};

    left = c / 2 * 3;
    right = (c - (c / 2)) * 3;
    c = 0;
    // deb(right); deb(left); deb(c); deb(a) ; deb(b);
    if (left != right)
    {
        if ((b & 1) == 1)
        {
            if (b > 0)
            {
                left += 2;
                b--;
                if (b > 0)
                {
                    left += (b / 2) * 2;
                    right += (b / 2) * 2;
                }
            }
        }
        else
        {
            if (b > 0)
            {
                left += 4;
                b -= 2;
                if (b > 0)
                {
                    left += (b / 2) * 2;
                    right += (b / 2) * 2;
                }
            }
        }

    }
    else
    {
        left = b / 2 * 2;
        right = (b - (b / 2)) * 2;
    }
// deb(right); deb(left); deb(c); deb(a) ; deb(b);
    if (left > right)
    {
        if (a >= (left - right))
        {
            a = a - (left - right);
            right = left;
            
            left += (a / 2) * 1;
            right += (a - a / 2) * 1;
            
        }
        else
        {
            right += a;
            a = 0;
        }
    }
    else if (right > left)
    {
        if (a >= (right - left))
        {
            a = a - (right - left);
            left = right;
            
            right += (a / 2) * 1;
            left += (a - a / 2) * 1;
            // cout << "yes" << endl;
        }
        else
        {
            left += a;
            a = 0;
        }
    }
    else
    {
        right += (a / 2) * 1;
        left += (a - a / 2) * 1;
    }
    // deb(left); deb(right);
    // deb(a);
    cout << abs(left - right) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
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
