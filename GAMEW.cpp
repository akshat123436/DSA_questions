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
    cin >> n;
    // int pow = 0;

    // while(n/2){
    //     n /=2;
    //     pow++;
    // }
    // cout << pow << endl;

    string s;
    cin >> s;

    char first =  s[0];
    int count = 1;
    for(int i= 0; i<n; i++){
        if(first != s[i]){
            count++;
            first = s[i];
        }
    }

    int num = count/2;

    int moves = num + 1;

    if((moves & 1) == 1){
        cout << "SAHID";
    }
    else{
        cout << "RAMADHIR";
    }
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

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
