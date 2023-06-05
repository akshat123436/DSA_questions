// // ------------Akshat Kothavade----------------
// // -----------CC : Akshat123436-----------------

// #include<bits/stdc++.h>
// using namespace std;
// #define gc getchar_unlocked
// #define fo(i,n) for(i=0;i<n;i++)
// #define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
// // #define int long long
// #define si(x)	scanf("%d",&x)
// #define sl(x)	scanf("%lld",&x)
// #define ss(s)	scanf("%s",s)
// #define pi(x)	printf("%d\n",x)
// #define pl(x)	printf("%lld\n",x)
// #define ps(s)	printf("%s\n",s)
// #define deb(x) cout << #x << " = " << x << endl
// #define deb2(x, y) cout << #x << " = " << x << "," << #y << " = " << y << endl
// #define PI 3.1415926535897932384626
// #define endl '\n'

// int mpow(int base, int exp); 

// const int mod = 1'000'000'007;
// const int N = 3e5, M = N;

// // void _print(int x ){ cerr<<x;} void _print(long long x ){ cerr<<x;}void  _print(unsigned long long x ){ cerr<<x;} void _print(char x ){ cerr<<x;}void  _print(float x ){ cerr<<x;} void _print(bool x ){ cerr<<x;}void _print(string x ){ cerr<<x;} 
 
// // template<class G> void _print(multiset<G>s){for(auto val : s )cout<<val<<endl;}
// // template<class G> void _print(set<G>s){for(auto val : s )cout<<val<<endl;}
 
// // void _print (unordered_map<int,int> x){cerr<<endl;unordered_map<int,int>::iterator ind;for(ind =x.begin() ; ind!=x.end() ; ind++ )cerr<<ind->first<<" -> "<<ind->second<<endl;}
// // void _print (unordered_map<long long,long long> x){cerr<<endl;unordered_map<long long,long long>::iterator ind;for(ind =x.begin() ; ind!=x.end() ; ind++ )cerr<<ind->first<<" -> "<<ind->second<<endl;}
// // void _print (unordered_map<char,int> x){cerr<<endl;unordered_map<char,int>::iterator ind;for(ind =x.begin() ; ind!=x.end() ; ind++ )cerr<<ind->first<<" -> "<<ind->second<<endl;}
// // void _print (unordered_map<float,float>x){cerr<<endl;unordered_map<float,float>::iterator ind;for(ind =x.begin() ; ind!=x.end() ; ind++ )cerr<<ind->first<<" -> "<<ind->second<<endl; }
// // template<class T>void sort(vector<T>&arr){sort(arr.begin(), arr.end());}
// // template<class T>void sort1(vector<T>&arr){sort(arr.begin()+1, arr.end());}

// // template<class T>void _print(T x )
// // {
// // for(int i=0 ; i<x.size() ; i++)
// // cerr<<x[i]<<' '; 
 
// // }
// // #ifndef ONLINE_JUDGE
// // #define debug(x)cerr<< #x<<' ';_print(x); cerr<<endl;
// // #else 
// // #define debug(x)
// // #endif

// #ifdef Priyansh31dec
// #define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
// #else
// #define debug(x);
// #endif
 
// // typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
 
// void _print(long long t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(long double t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(unsigned long long t) {cerr << t;}
 
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
// // void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// //          ------ LETS START 💫💫💫 -------

// void solve() {
//   int n;
//   unordered_map <int,int> example;

//   for(int i = 0; i<20 ;i++){
//       example[i] = i+1;
//   }
//   _print(example);
// }

// int32_t main() {
//     ios_base::sync_with_stdio(0), cin.tie(0);

//     int t = 1;
//     cin >> t;
//     while(t--) {
//       solve();
//     }

//     return 0;
// }

// int mpow(int base, int exp) {
//   base %= mod;
//   int result = 1;
//   while (exp > 0) {
//     if (exp & 1) result = ((int)result * base) % mod;
//     base = ((int)base * base) % mod;
//     exp >>= 1;
//   }
//   return result;
// }

