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

void _print(ll t) {cerr << t;}
//void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

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
bool inverse(char a, char b)
{
    if (a == 'R')
    {
        return b == 'P';
    }
    else if (a == 'P')
        return b == 'S';
    else
        return b == 'R';
}
char inv(char a)
{
    if (a == 'R')
    {
        return 'P';
    }
    else if (a == 'P')
        return 'S';
    else
        return 'R';
}
int32_t main()
{

    // fastio();

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    cin >> t;

    while (t--)
    {
        map<int, char> m;

        // cout << "---" << m[5] << "---"  << endl;
        int n;
        cin >> n;

        string s;
        cin >> s;
        string ans;
        ans.push_back(s[n - 1]);
        char ans_c = s[n - 1];
        char ans_inv = inv(s[n - 1]);
        vector<pair<char,int>> helper;
        char check = s[0];
        helper.push_back({s[0],1});
        int count = 1;
        int k = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] != check)
            {
                helper.push_back({s[i],1});
                check = s[i];
                k++;
            }
            else{
                helper[k].second++;
            }
        }
        
        // for(auto a : helper){
        //     cout << a.first << " " << a.second << endl;
        // }
        int size = helper.size();
        vector <char> answers(size);
        char ans_character = helper[size-1].first;
        if(size >= 2){
            answers[size-1] = helper[size-1].first;
            if(helper[size-2].first == inv(helper[size-1].first)) {
                answers[size-2] = inv(helper[size-1].first);
                ans_character = answers[size-2];
            }
            else{
                answers[size-2] = (helper[size-1].first);
                ans_character = answers[size-2];
            }
        }
        else{
            answers[size-1] = helper[size-1].first;
        }

        for(int i = size -2 ; i>0;i--){
            if(inverse(helper[i].first,helper[i-1].first)){
                if(inv(helper[i+1].first) == helper[i-1].first){
                    answers[i-1] = inv(answers[i+1]);
                }
                else{
                    answers[i-1] = answers[i+1];
                }
            }else{
                answers[i-1] = answers[i];
            }
        }

        for(int i = 0;i<size;i++){
            for(int j = 0;j<helper[i].second;j++){
                cout << answers[i];
            }
        }cout << endl;
        // for (int i = 0; i < n && count < helper.size(); i++)
        // {
        //     m[i] = helper[count + 2];
        //     if (s[i] != s[i + 1])
        //         count++;
        // }
        // for (int i = n - 1; i > 0; i--)
        // {
        //     if (inverse(s[i], s[i - 1]))
        //     {
        //         // cout << i << "dsl;fkjasd;fj"<< endl;
        //         if (inv(m[i - 1]) == s[i - 1])
        //         {
        //             if (ans_c == s[n - 1])
        //                 ans_c = ans_inv;
        //             else
        //                 ans_c = s[n - 1];
        //         }
        //     }
        //     ans.push_back(ans_c);
        // }
        // // debug(m);
        // // debug(helper);
        // // for(auto i : helper){
        // //     cout << i << " ";
        // // }cout << endl;
        // // cout << endl;
        // // for(auto i : m){
        // //     cout << i.first << " " << i.second <<endl;
        // // }cout << endl;
        // reverse(ans.begin(), ans.end());
        // cout << ans << endl;
    }
}