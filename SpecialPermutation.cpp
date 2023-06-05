#include <bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
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

int main() {

    #ifndef ONLINE_JUDGE

        freopen("Error.txt", "w", stderr);

    #endif

    int t=1;

    cin >> t;

    while(t--){
        ll n, left, right;
        cin >> n >> left >> right;
        int arr[n+1];
        for(int i = 1;i<=n;i++){
            arr[i] = i;
        }

        vector <ll> left_, right_;
        if(left < right){
            if(n/2 >= left && n/2 >= n-right+1){
                left_.push_back(left);
                ll count_l = 1;

                for(int i = right+1;i<=n;i++)
                {
                    left_.push_back(i);
                    count_l++;
                }
                int j = 1;
                while (count_l<n/2)
                {
                    left_.push_back(left+j);
                    j++;
                    count_l++;
                }
                right_.push_back(right);
                ll count_r = 1;

                for(int i = 1;i<left;i++)
                {
                    right_.push_back(i);
                    count_r++;
                }

                while (count_r<n/2)
                {
                    right_.push_back(left+j);
                    j++;
                    count_r++;
                }
                for(auto a : left_){
                    cout << a << " ";
                }
                for(auto a : right_){
                    cout << a << " ";
                }
                cout << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        else{
            if(n/2 == right && n/2 == n-left+1){
                
                for(int i = 1;i<=right ;i++){
                    right_.push_back(i);
                    
                }
                for(int i = right+1;i<=n;i++){
                    left_.push_back(i);
                }

                for(auto a : left_){
                    cout << a << " ";
                }
                for(auto a : right_){
                    cout << a << " ";
                }
                cout << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }

}