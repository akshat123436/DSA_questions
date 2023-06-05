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
#define maxi (int)(1e18 + 10)
// #define int long long

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

int lp[10000001];

int max_power(int num)
{
	int count = 0;

	while (num)
	{
		num /= 10;
		count++;
	}
	return --count;
}

bool isPrime[10000001];

void createSieve()
{

	for (int i = 0; i < 10000001; i++)
	{
		isPrime[i] = 1;
	}

	isPrime[0] = 0;
	isPrime[1] = 0;

	for (int i = 2; i <= 10000000; i++)
	{
		if (isPrime[i])
		{
			lp[i] = i;
			for (int j = 2 * i; j <= 10000000; j += i)
			{
				if (isPrime[j])
				{
					lp[j] = i;
				}
				isPrime[j] = 0;
			}
		}
	}
}

int numerator[10000001], denomenator[10000001];

int main()
{

	// fastio();

#ifndef ONLINE_JUDGE

	freopen("Error.txt", "w", stderr);

#endif

	int t = 1;

	createSieve();

	while (t--)
	{
		ll m, n;
		cin >> m >> n;

		ll up[m], down[n];

		for (int i = 0; i < m; i++)
		{
			cin >> up[i];
		}

		for (int i = 0; i < n; i++)
			cin >> down[i];

		for (int i = 0; i < m; i++)
		{

			ll num = up[i];

			ll div = lp[up[i]];

			while (num != 1)
			{
				debug(div);
				debug(num);
				while (num % div == 0)
				{
					num /= div;
					numerator[div]++;
				}
				div = lp[num];
			}
		}

		for (int i = 0; i < n; i++)
		{
			ll num = down[i];

			ll div = lp[down[i]];

			while (num != 1)
			{
				while (num % div == 0)
				{
					num /= div;
					if (numerator[div] > 0)
						numerator[div]--;
					else
						denomenator[div]++;
				}
				div = lp[num];
			}
		}

		vector<ll> upper_nums, below_nums;
		ll num = 1;
		for (int i = 0; i < 10000001; i++)
		{

			ll count = numerator[i];

			while (count)
			{

				while ((i)*num <= 10000000 && count)
				{
					num *= i;
					count--;
				}
				if ((i)*num > 10000000)
				{
					upper_nums.push_back(num);
					num = 1;
				}
			}
			if (num > 1 && i == 10000000)
				upper_nums.push_back(num);
		}
		num = 1;
		for (int i = 0; i < 10000001; i++)
		{

			ll count = denomenator[i];

			while (count)
			{
				while ((i)*num <= 10000000 && count)
				{
					num *= i;
					count--;
				}
				if ((i)*num > 10000000)
				{
					below_nums.push_back(num);

					num = 1;
				}
			}
			if (num > 1 && i == 10000000)
				below_nums.push_back(num);
		}
		if (!upper_nums.size())
			upper_nums.push_back(1);
		if (!below_nums.size())
			below_nums.push_back(1);
		cout << upper_nums.size() << " " << below_nums.size() << endl;

		for (auto a : upper_nums)
			cout << a << ' ';
		cout << endl;
		for (auto a : below_nums)
			cout << a << " ";
	}
}