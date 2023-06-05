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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x)       \
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
void _print(int t) { cerr << t; }
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

void MergeSort(vector<pair<string, int>> &v, int s, int e, int middle);
void MergeSortedIntervals(vector<pair<string, int>> &v, int s, int m, int e, int middle);

int main()
{

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;

	// cin >> t;

	while (t--)
	{
		int m, n;
		cin >> n >> m;

		std::vector<pair<string, int>> v;

		for (int i = 1; i <= n; i++)
		{
			string temp;
			cin >> temp;

			v.push_back(make_pair(temp, i));
		}
		// debug(v);
		MergeSort(v, 0, n-1, 0);
		int start = 0;
		for (int k = 1; k < m; )
		{
			int end = n-1;
			
			int check = v[0].first[k-1];
			for (int i = start; i < n; i++)
			{
				start = 0;
				if (v[i-1].first != check)
				{
					check = v[i-1].first;
					break;
				}
				else
				{
					
					end = i;
				}
			}
			MergeSort(v, start, end, k);
			if(end == n-1){
				k++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << v[i].second << " ";
		}
		// debug(v);
		cout << endl;
	}
}
void MergeSortedIntervals(vector<pair<string, int>> &v, int s, int m, int e, int middle)
{

	// temp is used to temporary store the vector obtained by merging
	// elements from [s to m] and [m+1 to e] in v
	vector<pair<string, int>> temp;

	int i, j;
	i = s;
	j = m + 1;
	if ((middle & 1) == 0)
	{
		while (i <= m && j <= e)
		{
			if (middle == 0)
			{
				if (v[i].first[middle] <= v[j].first[middle])
				{
					temp.push_back(v[i]);
					++i;
				}
			}
			else if (v[i].first[middle] <= v[j].first[middle] && v[i].first[middle - 1] >= v[j].first[middle - 1])
			{
				temp.push_back(v[i]);
				++i;
			}
			else
			{
				temp.push_back(v[j]);
				++j;
			}
		}

		while (i <= m)
		{
			temp.push_back(v[i]);
			++i;
		}

		while (j <= e)
		{
			temp.push_back(v[j]);
			++j;
		}
	}
	else
	{
		while (i <= m && j <= e)
		{

			if (v[i].first[middle] >= v[j].first[middle] && v[i].first[middle - 1] <= v[j].first[middle - 1])
			{
				temp.push_back(v[i]);
				++i;
			}
			else
			{
				temp.push_back(v[j]);
				++j;
			}
		}

		while (i <= m)
		{
			temp.push_back(v[i]);
			++i;
		}

		while (j <= e)
		{
			temp.push_back(v[j]);
			++j;
		}
	}
	for (int i = s; i <= e; ++i)
		v[i] = temp[i - s];
}

// the MergeSort function
// Sorts the array in the range [s to e] in v using
// merge sort algorithm
void MergeSort(vector<pair<string, int>> &v, int s, int e, int middle)
{
	if (s < e)
	{
		int m = (s + e) / 2;
		// debug(s);
		// debug(m);
		// debug(middle);
		// debug(e);
		MergeSort(v, s, m, middle);
		MergeSort(v, m + 1, e, middle);
		MergeSortedIntervals(v, s, m, e, middle);
	}
}