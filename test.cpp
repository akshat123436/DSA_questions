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
    if (a == 0)
        return false;
    if (b == 0)
        return true;
    if (a < b)
        return true;
    if (a > b)
        return false;
    return true;
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
vector<int> orderPizza(vector<int> orderPlaced, int sizee)
{
    vector<int> answer;
    int ptr = 0;
    queue<pair<int, int>> meatQueue;
    int i = 0;
    for (auto a : orderPlaced)
    {
        if (a < 0)
            meatQueue.push({a, i});
        i++;
    }
    while (ptr <= orderPlaced.size() - sizee)
    {
        if (meatQueue.size())
        {
            if (meatQueue.front().first == orderPlaced[ptr])
            {
                answer.push_back(meatQueue.front().first);
                meatQueue.pop();
            }
            else
            {
                if (ptr + sizee - 1 < meatQueue.front().second)
                {
                    answer.push_back(0);
                }
                else
                {
                    answer.push_back(meatQueue.front().first);
                }
            }
        }
        else
        {
            answer.push_back(0);
        }
        ptr++;
    }
    return answer;
}
char lostCharNW(string stringSent, string stringRec)
{

    for (int i = 0; i < stringRec.length(); i++)
    {
        if (stringSent[i] != stringRec[i])
        {
            return stringSent[i];
        }
    }
    return stringSent[stringSent.length() - 1];
}
vector<string> dictwords(string textInput)
{
    vector<string> answer;
    unordered_map<string, int> m;
    string word;
    for (int i = 0; i < textInput.size(); i++)
    {
        if (textInput[i] != ' ')
        {
            word.push_back(textInput[i]);
        }
        else
        {
            m[word]++;
            word = "";
        }
    }
    if (textInput[textInput.size() - 1] != ' ')
        m[word]++;
    for (auto &i : m)
    {
        if (i.second > 1)
        {
            answer.push_back(i.first);
        }
    }
    if ()
        sort(answer.begin(), answer.end());
    return answer;
}

vector<int> streetLight(vector<int> currentState, int days)
{
    vector<int> answer;
    int prev = 0;
    for (int i = 0; i < days; i++)
    {
        for (int j = 0; j < (int)(currentState.size()); j++)
        {
            int ahead = 0;
            if(j!=(int)(currentState.size())-1){
                ahead = currentState[j+1];
            }
            else ahead = 0;
            if ((prev == 0 && ahead) || (prev && !ahead))
            {
                
            }
            else
            {
            }
        }
    }
}
return answer;
}
int32_t main()
{

    fastio();

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    // cin >> t;
    vector<string> temp = dictwords("cat batman latt matter cat matter cat");
    for (auto a : temp)
        cout << a << endl;
}