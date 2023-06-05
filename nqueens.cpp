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

// void _print(ll t) {cerr << t;}
////void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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
class Solution
{
public:
    void solver(vector<vector<string>> &ans, vector<vector<int>> &pos, int row, int n, vector<bool> &upper_diagonal, vector<bool> &lower_diagonal, vector<bool> &general_diagonal, vector<bool> &rowCheck, vector<bool> &columnCheck)
    {
        if (row == n)
        {
            vector<string> current;
            for (int i = 0; i < n; i++)
            {
                string temp;
                for (int j = 0; j < n; j++)
                {
                    if (pos[i][j])
                        temp.push_back('Q');
                    else
                        temp.push_back('.');
                }
                current.push_back(temp);
            }
            ans.push_back(current);
            return;
        }

        for (int column = 0; column < n; column++)
        {
            if (row > column)
            {
                if (!rowCheck[row] && !columnCheck[column] && !lower_diagonal[row - column] && !general_diagonal[row + column])
                {
                    pos[row][column] = 1;
                    rowCheck[row] = true;
                    columnCheck[column] = true;
                    lower_diagonal[row - column] = true;
                    general_diagonal[row + column] = true;
                    solver(ans, pos, row + 1, n, upper_diagonal, lower_diagonal, general_diagonal, rowCheck, columnCheck);
                    pos[row][column] = 0;
                    rowCheck[row] = false;
                    columnCheck[column] = false;
                    lower_diagonal[row - column] = false;
                    general_diagonal[row + column] = false;
                }
            }
            else
            {
                if (!rowCheck[row] && !columnCheck[column] && !upper_diagonal[column - row] && !general_diagonal[row + column])
                {
                    pos[row][column] = 1;
                    rowCheck[row] = true;
                    columnCheck[column] = true;
                    upper_diagonal[column - row] = true;
                    general_diagonal[row + column] = true;
                    solver(ans, pos, row + 1, n, upper_diagonal, lower_diagonal, general_diagonal, rowCheck, columnCheck);
                    pos[row][column] = 0;
                    rowCheck[row] = false;
                    columnCheck[column] = false;
                    upper_diagonal[column - row] = false;
                    general_diagonal[row + column] = false;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<vector<int>> pos(n, vector<int>(n, 0));
        vector<bool> upper_diagonal(n,0), lower_diagonal(n,0), general_diagonal(2*n,0), rowCheck(n,0), columnCheck(n,0);
        solver(ans, pos, 0, n, upper_diagonal, lower_diagonal, general_diagonal, rowCheck, columnCheck);
        return ans;
    }
};
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
    }
}