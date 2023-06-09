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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
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
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

bool isNotPrime(int n){
    for(int i = 2; i*i<=n; i++){
        if(n%i == 0){
            return true;
        }
    }
    return false;
}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("Error.txt", "w", stderr);
	#endif

	int t=1;

	cin >> t;

	while(t--){
        int n, k;
        cin >> n >> k;
        int even_num = n/2;
        vector <int> even_numbers, odd_numbers;

        for(int i = 2; i<=n; i+=2){
            even_numbers.push_back(i);
        }
        for(int i = 3; i<=n; i+=2){
            if(i*2 <=n){
                even_num++;
                even_numbers.push_back(i);
            }
            else if(isNotPrime(i)){
                even_num++;
                even_numbers.push_back(i);
            }
            else{
                odd_numbers.push_back(i);
            }
        }
        int odd_num = n-even_num-1;
        if(k==even_num || k <= odd_num || k == odd_num+1 || k==even_num+1 || k==1 || k>=even_num && k<=n){
            cout << "YES" << endl;
            if(k==even_num){
                for(auto a : even_numbers){
                    cout << a << " ";
                }
            }
            else if(k==1){
                cout << 1 ;
            }
            else if(k==even_num+1){
                for(auto a : even_numbers){
                    cout << a << " ";
                }
                cout << 1 ;
            }
            else if(k == odd_num+1){
                for(auto a : odd_numbers){
                    cout << a << " ";
                }
                cout << 1 ;
            }
            else if(k<=odd_num)
            {
                for(int i = 0;i<k;i++){
                    cout << odd_numbers[i] << " ";
                }
            }
            else {
                int count = 0;
                for(auto a : even_numbers){
                    cout << a << " ";
                    count++;
                }
                cout << 1 << " ";
                count++;
                for(int i = 0;count<k;i++,count++){
                    cout << odd_numbers[i] <<  " ";
                }
                
            }
        }
        else{
            cout << "NO";
        }
        cout << endl;
	}
}
