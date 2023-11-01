/*

1-> One day I will be 6* at Codechef and CandidateMaster at CodeForces

2-> Journey is not going to be so easy , sometimes shitty thoughts will rain on me
    but that should not be the end , prevent self giving up at that moment .
    CP is not a fight , it is Love .

3-> Dont panic about rating , rating takes time to come to your level
    Dont forget rating is direcly propotional to skills , skills are not directly
    propotional to rating.

4-> Keep on practising the questions above your level.

5-> Keep helping people , fellow programmers , junior , create a healthy coding environment.
    Keep learning everyday .

6-> Be Honest to Yourself.

*/

#include <bits/stdc++.h>
using namespace std;
#define fori(a, b, c) for (int i = a; i < b; i += c)
#define forj(a, b, c) for (int j = a; j < b; j += c)
#define forf(a, b, c) for (int f = a; f < b; f += c)
#define tt    \
    int f;    \
    cin >> f; \
    while (f--)

#define mp make_pair
#define pb push_back
#define um unordered_map
#define si set<int>

#define ull unsigned long long int
#define ll long long int

#define mod 1000000007
#define inf 2147483647
#define ninf -2147483648
#define llmax 9223372036854775807

#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>

#define vp vector<pair<int, int>>
#define vpci vector<pair<char, int>>
#define vpll vector<pair<ll, ll>>
#define vv vector<vector<int>>
#define vc vector<char>
#define vs vector<string>

#define fr first
#define sc second

#define st SegmentTree
#define endl '\n'

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// there are two functionf of this
// s.find_by_order(int x);  - > finds out the number of elements strictly lesser than x in ordered set s
// s.order_of_key(int i)  -> this return iterator to the value at index i in O log(n) time

// Premetive Data Types
void _print(int x) { cerr << x; }
void _print(ll x) { cerr << x; }
void _print(ull x) { cerr << x; }
void _print(char x) { cerr << x; }
void _print(float x) { cerr << x; }
void _print(bool x) { cerr << x; }
void _print(string x) { cerr << x; }

// SET

template <class G>
void _print(multiset<G> s)
{
    for (auto val : s)
        cout << val << endl;
}
template <class G>
void _print(set<G> s)
{
    for (auto val : s)
        cout << val << endl;
}
void _print(set<int> &arr)
{
    for (auto a : arr)
        cerr << a << " ";
    cerr << endl;
}
void _print(set<pair<int, int>> &arr)
{
    for (auto a : arr)
        cerr << "(" << a.first << "," << a.second << ")  ";
    cerr << endl;
}

// Unordered Map

template <class G>
void _print(um<G, G> x)
{
    cerr << endl;
    for (auto a : x)
    {
        cerr << "(" << a.first << "," << a.second << ")";
    }
    cerr << endl;
}

// Map
template <class G>
void _print(map<G, G> x)
{
    cerr << endl;
    for (auto a : x)
    {
        cerr << "(" << a.first << "," << a.second << ")";
    }
    cerr << endl;
}

// Vector
void _print(vector<pair<int, int>> &arr)
{
    fori(0, arr.size(), 1) { cerr << "(" << arr[i].first << "," << arr[i].second << ") "; }
    cerr << endl;
}

void _print(vector<vi> &graph)
{
    cerr << endl;
    fori(1, graph.size(), 1)
    {
        cerr << i << " -> ";
        forj(0, graph[i].size(), 1)
        {
            cerr << graph[i][j] << " ";
        }
        cerr << endl;
    }
}

void _print(vector<pair<int, pair<int, int>>> &arr)
{
    fori(0, arr.size(), 1)
    {
        cerr << "(" << arr[i].first << "," << arr[i].second.first << "," << arr[i].second.second << ") ";
    }
    cerr << endl;
}

template <class T>
void _print(T x)
{
    for (int i = 0; i < x.size(); i++)
        cerr << x[i] << ' ';
}

// Vector Sort
template <class T>
void sort(vector<T> &arr) { sort(arr.begin(), arr.end()); }
template <class T>
void sort1(vector<T> &arr) { sort(arr.begin() + 1, arr.end()); }

// Vector and String Reverse
template <class F>
void reverse(vector<F> &arr)
{
    reverse(arr.begin(), arr.end());
}

template <class F>
void reverse1(vector<F> &arr)
{
    reverse(arr.begin() + 1, arr.end());
}

void reverse(string &arr)
{
    reverse(arr.begin(), arr.end());
}

void reverse1(string &arr)
{
    reverse(arr.begin() + 1, arr.end());
}

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << ' '; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "enter a number : ";
    int n;
    cin >> n;
    cout << n << endl;
}
