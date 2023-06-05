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

Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    Node *arr[n][n];
    int i,j;
    for( i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            arr[i][j]=new Node(mat[i][j]);
        }
    }
    for( i=0;i<n;i++)
    {
        for( j=0;j<n;j++)
        {
        	if(i!=n-1)
            arr[i][j]->down=arr[i+1][j];
            if(j!=n-1)
            arr[i][j]->right=arr[i][j+1];
        }
    }
    for(j=0;j<n;j++)
    {
        arr[n-1][j]->down=NULL;
    }
    for(i=0;i<n;i++)
    {
        arr[i][n-1]->right=NULL;
    }
    return arr[0][0];

}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("Error.txt", "w", stderr);
	#endif

	int t=1;

	cin >> t;

	while(t--){

	}
}
