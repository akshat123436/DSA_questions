#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define maxi (int)(1e7 + 10)
#define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

//void _print(ll t) {cerr << t;}
////void _print(int t) {cerr << t;}
//void _print(string t) {cerr << t;}
//void _print(char t) {cerr << t;}
//void _print(lld t) {cerr << t;}
//void _print(double t) {cerr << t;}
//void _print(ull t) {cerr << t;}

//template <class T, class V> void _print(pair <T, V> p);
//template <class T> void _print(vector <T> v);
//template <class T> void _print(set <T> v);
//template <class T, class V> void _print(map <T, V> v);
//template <class T> void _print(multiset <T> v);
//template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
//template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
//template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
//template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
//template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//---------------------------------------------------------------------------------------------------------------------------------------

bool cmp(int a, int b)
{
    return a < b;
}
bool accumulator(int a, int b)
{
    return a + b;
}
// Function to find the value of
// P * Q^-1 mod 998244353
long long calculate(long long p, long long q)
{
    long long mod = 998244353, expo;
    expo = mod - 2;
    // Loop to find the value
    // until the expo is not zero
    while (expo)
    {
        // Multiply p with q
        // if expo is odd
        if (expo & 1)
        {
            p = (p * q) % mod;
        }
        q = (q * q) % mod;
        // Reduce the value of
        // expo by 2
        expo >>= 1;
    }
    return p;
}

int32_t main()
{

    fastio();

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int num = 2, i = 1;
        int two = 2;
        map<int, int> index;
        int power = 0;

        int m = n;
        map<int, int> answer;
        while (m > 1)
        {
            m /= 2;
            power++;
        }
        bool istwo = false;

        int temp = pow(2, power);

        if (temp == n)
            istwo = true;
        if (istwo)
        {

            for (int j = 2; j < n; j++)
            {
                int num = j;
                int steps = 0;
                do
                {
                    // cout << num << " ";
                    if (num % two == 0)
                    {
                        num = n / two + num / two;
                    }
                    else
                    {
                        num = (num + ll(1)) / two;
                    }
                    // cout << i << " " << num << endl;

                    // cout << num << endl;
                    steps++;
                } while (j != num);

                int answer_steps = k % steps;
                num = j;
                for (int k = 0; k < answer_steps; k++)
                {

                    if (num % two == 0)
                    {
                        num = n / two + num / two;
                    }
                    else
                    {
                        num = (num + ll(1)) / two;
                    }
                }
                // cout << num << " " << j << endl;
                answer[num] = j;
            }
        }
        else
        {
            map<int, int> diff;
            do
            {
                // cout << num << " ";
                if (num % two == 0)
                {
                    num = n / two + num / two;
                }
                else
                {
                    num = (num + ll(1)) / two;
                }
                // cout << i << " " << num << endl;
                if (num == two)
                {
                    index[0] = num;
                    diff[num] = 0;
                }
                else
                {
                    index[i] = num;
                    diff[num] = i;
                }
                // cout << num << endl;
                i++;
            } while (num != two);

            i -= 1;

            int ans_index = k % i;

            for (int j = 2; j < n; j++)
            {
                // cout << j << " " << i << " " << ans_index << " " << diff[j] << " " << n << " " << (ans_index + diff[j]) % (i) << " " << index[(ans_index + diff[j]) % (i)] << endl;
                answer[index[(ans_index + diff[j]) % (i)]] = j;
            }
        }
        cout << 1 << " ";
        for (int j = 2; j < n; j++)
        {
            if (answer[j] == 0)
            {
                int num = j;
                int steps = 0;
                do
                {
                    // cout << num << " ";
                    if (num % two == 0)
                    {
                        num = n / two + num / two;
                    }
                    else
                    {
                        num = (num + ll(1)) / two;
                    }
                    // cout << i << " " << num << endl;

                    // cout << num << endl;
                    steps++;
                } while (j != num);

                int answer_steps = k % steps;
                num = j;
                for (int k = 0; k < answer_steps; k++)
                {

                    if (num % two == 0)
                    {
                        num = n / two + num / two;
                    }
                    else
                    {
                        num = (num + ll(1)) / two;
                    }
                }
                // cout << num << " " << j << endl;
                answer[num] = j;
            }
            cout << answer[j] << endl;
        }
        cout << n << endl;
    }
}