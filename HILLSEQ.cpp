#include<bits/stdc++.h>

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

ll t;
cin>> t;
while(t--){
	ll n;
	cin >> n;

	ll  arr[n];
	map <ll, ll> count;
	bool isrepeated = false;
	ll max_num = INT_MIN;
	bool impossible = false;
	
	for(ll i = 0; i<n; i++){
		cin >> arr[i];
		if(arr[i] > max_num){
			max_num = arr[i];
		}
		count[arr[i]]++;
		if(count[arr[i]] > 2){
			// debug(arr[i]);
			impossible = true;
			break;
		}
	}
	if(count[max_num] >= 2){
		// debug(max_num);
		impossible = true;
	}
	// debug(count);
	if(impossible){
		cout << -1 << endl;
	}
	else{

			vector <ll> repeated;
			vector <ll> normal;

			auto iterator_ = count.begin();

			for(; iterator_ != count.end(); iterator_++){
				if(iterator_->second == 2){
					repeated.push_back(iterator_->first);
					normal.push_back(iterator_->first);
				}
				else{
					normal.push_back(iterator_->first);
				}
			}

			sort(repeated.begin(), repeated.end());
			sort(normal.begin(), normal.end(), greater <ll> ());

			// debug(repeated);
			// debug(normal);
			for(auto a : repeated){
				cout << a << " ";
			}
			for(auto a : normal){
				cout << a << " ";
			}
			cout << endl;
		}

}
}
