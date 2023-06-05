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

        int series = n - 1;
        if (n == 1)
        {
            cout << 1 << ' ' << 1 << endl;
        }
        else
        {
            for (int i = 1; i <= series; i++)
            {
                cout << i << " ";
            }
            cout << series << " ";
            int sum = series * (series + 1) / 2 + (series);
            int add = pow(2,n);
            cout << add - sum << endl;
        }
    }
}