// #include <bits/stdc++.h>

// using namespace std;

// #define fastio()                    \
//   ios_base::sync_with_stdio(false); \
//   cin.tie(NULL)
// #define MOD 1000000007
// #define MOD1 998244353
// #define INF 1e18
// #define endl "\n"
// #define pb push_back
// #define ppb pop_back
// #define mp make_pair
// #define ff first
// #define ss second
// #define PI 3.141592653589793238462
// #define set_bits __builtin_popcountll
// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()
// #define maxi (int)(1e7 + 10)
// #define int long long

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;

// #ifndef ONLINE_JUDGE
// #define debug(x)     \
//   cerr << #x << " "; \
//   _print(x);         \
//   cerr << endl;
// #else
// #define debug(x)
// #endif

// // void _print(ll t) {cerr << t;}
// ////void _print(int t) {cerr << t;}
// // void _print(string t) {cerr << t;}
// // void _print(char t) {cerr << t;}
// // void _print(lld t) {cerr << t;}
// // void _print(double t) {cerr << t;}
// // void _print(ull t) {cerr << t;}

// // template <class T, class V> void _print(pair <T, V> p);
// // template <class T> void _print(vector <T> v);
// // template <class T> void _print(set <T> v);
// // template <class T, class V> void _print(map <T, V> v);
// // template <class T> void _print(multiset <T> v);
// // template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
// // template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// // template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// // template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// // template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// //---------------------------------------------------------------------------------------------------------------------------------------

// bool cmp(int a, int b)
// {
//   return a < b;
// }
// bool accumulator(int a, int b)
// {
//   return a + b;
// }
// // Function to find the value of
// // P * Q^-1 mod 998244353
// long long calculate(long long p, long long q)
// {
//   long long mod = 998244353, expo;
//   expo = mod - 2;
//   // Loop to find the value
//   // until the expo is not zero
//   while (expo)
//   {
//     // Multiply p with q
//     // if expo is odd
//     if (expo & 1)
//     {
//       p = (p * q) % mod;
//     }
//     q = (q * q) % mod;
//     // Reduce the value of
//     // expo by 2
//     expo >>= 1;
//   }
//   return p;
// }
// class business
// {
// private:
//   map<int, int> parent;
//   map<int, double> balance;

// public:
//   // id 0 can be assumed to be the  root parent of all the employees;
//   business()
//   {
//     parent[0] = -1;
//   }

//   void addEmployee(int parentId, int childId)
//   {
//     parent[childId] = parentId;
//   }

//   void addSaleAmount(double amount, int empId)
//   {
//     if (empId == 0)
//       return;
//     balance[empId] += amount;

//     addSaleAmount(amount / 10, parent[empId]);
//   }

//   double getBalance(int empId)
//   {
//     return balance[empId];
//   }
// };

// int32_t main()
// {

//   fastio();

// #ifndef ONLINE_JUDGE

//   freopen("Error.txt", "w", stderr);

// #endif

//   int t = 1;

//   // cin >> t;

//   while (t--)
//   {
//     business *obj = new business();
//     obj->addSaleAmount(100, 1);
//     cout << obj->getBalance(1);
//     cout << endl
//          << endl;
//     obj->addEmployee(1, 2);
//     obj->addSaleAmount(100, 2);
//     cout << obj->getBalance(1);
//     cout << endl;
//     cout << obj->getBalance(2);
//     cout << endl
//          << endl;
//     obj->addEmployee(2, 3);
//     obj->addSaleAmount(100, 3);
//     cout << obj->getBalance(1);
//     cout << endl;
//     cout << obj->getBalance(2);
//     cout << endl;
//     cout << obj->getBalance(3);
//     cout << endl
//          << endl;
//   }
// }

#include <bits/stdc++.h>

using namespace std;

#define fastio()                    \
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
// #define int long long

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)     \
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
class arr
{
public:
  pair<int, int> findSecondMax(int n, int *v)
  {
    int original[n];
    for (int i = 0; i < n - 1; i++)
    {
      cin >> v[i];
      original[i] = v[i];
    }

    v[n] = 0;
    original[n] = 0;
    int totalCount = 0;
    int sizee = n;
    int s2 = ceil(log2(n)) + 1;
    int arr[n], temp[n];
    for (int i = 0; i < n; i++)
    {
      arr[i] = i;
      temp[i] = i;
    }
    int cmpSize = (int)(ceil(log2(n)));
    int comparedElements[n][cmpSize];
    int count = 0;
    for (int i = 0; i < s2; i++)
    {
      int c2 = 0;
      int nextLevelSize = ceil((sizee - 1) / 2.0) + 1;
      int *nextLevel = new int[nextLevelSize];

      for (int j = 0; j < sizee - 1; j += 2)
      {
        int maxOfTwo = 0;
        int minOfTwo = 0;
        if (original[arr[j]] > original[arr[j + 1]])
        {
          totalCount++;
          maxOfTwo = arr[j];
          minOfTwo = original[arr[j + 1]];
        }
        else
        {
          totalCount++;
          maxOfTwo = arr[j + 1];
          minOfTwo = original[arr[j]];
        }
        comparedElements[maxOfTwo][count] = minOfTwo;
        nextLevel[c2] = maxOfTwo;
        c2++;
      }

      for (int k = 0; k < c2; k++)
      {
        arr[k] = nextLevel[k];
      }
      arr[c2] = n - 1;
      sizee = sizee / 2 + 1;
      count++;
    }
    int maxElementIndex = arr[0];
    cout << maxElementIndex << endl;
    int secMax = comparedElements[maxElementIndex][0];
    for (int i = 1; i < cmpSize; i++)
    {
      secMax = max(comparedElements[maxElementIndex][i], secMax);
      totalCount++;
    }
    return {secMax, totalCount};
  }
};
int32_t main()
{

  fastio();

#ifndef ONLINE_JUDGE

  freopen("Error.txt", "w", stderr);

#endif

  int t = 1;

  // cin >> t;

  while (t--)
  {
    int n;
    cin >> n;
    n++;
    // cout << n << endl;
    int *v = new int[n];
    // cout << n << endl;
    arr *obj = new arr();

    auto a = obj->findSecondMax(n, v);

    cout << "Verdict : " << a.first << " " << a.second << endl;
  }
}