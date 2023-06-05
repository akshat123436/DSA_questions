#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (i >= (arr[i] - 1))
            {
                ans += (n - i);
            }
        }
        cout << ans << endl;
    }
}