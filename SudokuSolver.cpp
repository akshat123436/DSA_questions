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

void _print(ll t)
{
    cerr << t;
}
// void _print(int t) {cerr << t;}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

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
    void solver(vector<vector<bool>> &row, vector<vector<bool>> &column, vector<vector<vector<bool>>> &section, vector<vector<char>> &ans, vector<vector<char>> &board, int rowIndex, int colIndex, bool &found)
    {

        if (found)
        {
            return;
        }
        if (rowIndex == 9)
        {
            found = true;
            return;
        }
        if (colIndex == 9)
        {
            solver(row, column, section, ans, board, rowIndex + 1, 0, found);
        }
        for (int j = colIndex; j < 9; j++)
        {
            if (board[rowIndex][j] == '.')
            {
                for (int i = 1; i <= 9; i++)
                {
                    int secRow = 0, secCol = 0;

                    if (rowIndex >= 0 && rowIndex <= 2)
                        secRow = 0;
                    if (rowIndex >= 3 && rowIndex <= 5)
                        secRow = 1;
                    if (rowIndex >= 6 && rowIndex <= 8)
                        secRow = 2;

                    if (j >= 0 && j <= 2)
                        secCol = 0;
                    if (j >= 3 && j <= 5)
                        secCol = 1;
                    if (j >= 6 && j <= 8)
                        secCol = 2;

                    if (!row[rowIndex][i] && !column[j][i] && !section[secRow][secCol][i])
                    {
                        cout << rowIndex << " " << j << endl;
                        cout << "i " << i << endl;
                        ans[rowIndex][j] = i;
                        row[rowIndex][i] = true;
                        column[j][i] = true;
                        section[secRow][secCol][i] = true;
                        solver(row, column, section, ans, board, rowIndex, j + 1, found);
                        ans[rowIndex][]
                        row[rowIndex][i] = false;
                        column[j][i] = false;
                        section[secRow][secCol][i] = false;
                    }
                }
            }
        }
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        vector<vector<bool>> row(9, vector<bool>(10, 0)), column(9, vector<bool>(10, 0));
        vector<vector<vector<bool>>> section(3, vector<vector<bool>>(3, vector<bool>(10, 0)));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int digit = board[i][j] - '0';
                    row[i][digit] = true;
                    column[j][digit] = true;
                    int rowIndex = 0, colIndex = 0;

                    if (i >= 0 && i <= 2)
                        rowIndex = 0;
                    if (i >= 3 && i <= 5)
                        rowIndex = 1;
                    if (i >= 6 && i <= 8)
                        rowIndex = 2;

                    if (j >= 0 && j <= 2)
                        colIndex = 0;
                    if (j >= 3 && j <= 5)
                        colIndex = 1;
                    if (j >= 6 && j <= 8)
                        colIndex = 2;

                    section[rowIndex][colIndex][digit] = true;
                }
            }
        }
        // debug(row);
        // debug(column);
        // debug(section);
        // for (auto a : row)
        // {
        //     for (auto b : a)
        //         cout << b << " ";
        //     cout << endl;
        // }
        // cout << "\ncolumne\n";
        // for (auto a : column)
        // {
        //     for (auto b : a)
        //         cout << b << " ";
        //     cout << endl;
        // }
        // cout << "\nSection\n";
        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         for (auto a : section[i][j])
        //             cout << a << " ";
        //         cout << endl;
        //     }
        // }
        vector<vector<char>> ans = board;
        // debug(ans);
        bool found = false;
        solver(row, column, section, ans, board, 0, 0, found);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                board[i][j] = ans[i][j];
            }
        }
    }
};

int32_t main()
{

    // fastio();

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    // cin >> t;

    while (t--)
    {
        Solution temp;
        vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        temp.solveSudoku(board);
    }
}