#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
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
#define maxi 1e7 + 10;

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

/*void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
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
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}*/
char input[1000][1000];
char input2[1000][1000];
int main()
{

#ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);

#endif

    int t = 1;

    // cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> input[i][j];
                input2[i][j] = input[i][j];
            }
        }

        // for(int i = 1;i<=n;i++){
        //     for(int j = 1;j<=m;j++){
        //         if(input[i][j] == '.'){
        // if(input[i][j-1] != 'W' && input[i][j+1] != 'W' && input[i-1][j] != 'W' && input[i+1][j] != 'W'){
        //     input[i][j] = 'W';
        // }
        // else{
        //     input[i][j] = 'B';
        // }
        //             if(input[i][j-1] != 'B' && input[i][j+1] != 'B' && input[i-1][j] != 'B' && input[i+1][j] != 'B'){
        //                 input[i][j] = 'B';
        //             }
        //             else{
        //                 input[i][j] = 'W';
        //             }
        //         }
        //     }
        // }

        // for(int i = 1;i<=n;i++){
        //     for(int j = 1;j<=m;j++){
        //         if(input2[i][j] == '.'){
        //             if(input2[i][j-1] != 'W' && input2[i][j+1] != 'W' && input2[i-1][j] != 'W' && input2[i+1][j] != 'W'){
        //                 input2[i][j] = 'W';
        //             }
        //             else{
        //                 input2[i][j] = 'B';
        //             }
        //         }
        //     }
        // }
        // bool isFirst = true;
        // for(int i = 1;i<=n;i++){
        //     for(int j = 1;j<=m;j++){
        //         if(input[i][j] != '-' && (input[i][j-1] == input[i][j] || input[i][j+1] == input[i][j] || input[i+1][j] == input[i][j] || input[i-1][j] == input[i][j])){
        //             cout << " " << input[i-1][j] << " " << endl;
        //             cout << input[i][j-1] << input[i][j] << input[i][j+1] << endl;
        //             cout << " " << input[i+1][j] << " " << endl;
        //             isFirst = false;
        //             break;
        //         }
        //     }if(!isFirst) break;
        // }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (input[i][j] == '.')
                {
                    if (i % 2 == 1)
                    {
                        if (j % 2 == 1)
                        {
                            input[i][j] = 'W';
                        }
                        else
                        {
                            input[i][j] = 'B';
                        }
                    }
                    else
                    {
                        if (j % 2 == 1)
                        {
                            input[i][j] = 'B';
                        }
                        else
                        {
                            input[i][j] = 'W';
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                cout << input[i][j];
            }
            cout << endl;
        }
    }
    // if(isFirst){
    //     cout << " first "  << endl;
    //     for(int i =1 ;i<=n;i++){
    //         for(int j =1 ;j<=m;j++){

    //             cout << input[i][j] ;
    //         }cout << endl;
    //     }
    // }

    // }
}