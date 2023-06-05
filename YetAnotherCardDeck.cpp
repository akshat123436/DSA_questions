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

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("Error.txt", "w", stderr);
	#endif

	int t=1;

	// cin >> t;

	while(t--){
        int n, q;
        cin >> n >> q;

        map <int, int> index;
        int first;
        cin >> first;
        index[first] = 1;
        for(int i = 0; i<n-1 ;i++){
            int temp;
            cin >> temp;
            if(index[temp] == 0){
                index[temp] = i+2;
            }
        }
        debug(index);
        vector <int> ans;
        for(int i = 0; i<q; i++){
            int num;
            cin >> num;
            ans.push_back(index[num]);
            for(auto a = index.begin(); a!=index.end(); a++){
                if(a->second < index[num]){
                    debug(a->second);
                    a->second = a->second + 1;
                }
                debug(index);
            }
            index[num] = 1;
        }
        debug(index);
        for(auto a : ans){
            cout << a << " ";
        }
        cout << endl;
	}
}