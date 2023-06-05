#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int32_t main()
{
    ios_base ::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    int arr[n];
    int sum[n];
    int sum_ = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum_ += arr[i];
        sum[i] = sum_;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        int j, k;
        cin >> j >> k;
        int val = 0;
        if (j != 0)
        {
            val = sum[k] - sum[j-1];
        }
        else
        {
            val = sum[k];
        }
        cout << val << endl;
    }
}
