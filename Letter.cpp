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
    int n;
    string heading, letter;
    getline(cin, heading);
    getline(cin, letter);
    map<char, int> available;
    int heading_len = heading.length();
    for (int i = 0; i < heading_len; i++)
    {
        if (heading[i] != ' ')
        {
            available[heading[i]]++;
        }
    }
    int letter_len = letter.length();
    bool insufficient = false;
    for (int i = 0; i < letter_len; i++)
    {
        if (letter[i] != ' ')
        {
            if (available[letter[i]] > 0)
            {
                available[letter[i]]--;
            }
            else{
                insufficient = true;
                break;
            }
        }
    }
    if(insufficient){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
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
