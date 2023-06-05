#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int32_t main()
{
    // ios_base ::sync_with_stdio(0);
    // cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int max = INT_MIN;
        int min = INT_MAX;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > max)
            {
                max = arr[i];
            }
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }

        int left[n] = {}, right[n] = {};
        sort(arr, arr + n, greater<int>());
        for (int i = 1; i < n; i++)
        {
            left[i] = max - arr[i];
        }
        sort(arr, arr + n);
        int second_smallest = arr[1];
        for (int i = 1; i < n; i++)
        {
            right[i] = arr[i]-min ;
        }
        sort(arr, arr + n, greater<int>());
        int second_largest = arr[1];
        int diff = INT_MAX;
        for (int i = 1; i < n-1; i++)
        {
            int temp = abs(left[i] - right[i]);
            if ((temp<diff && (n&1) == 0) || temp < diff && ((n&1) == 1 && i != n/2))
            {
                diff = temp;
            }
        }
        int case1 = second_largest - min;
        int case2 = max - second_smallest;

        if (case1 < diff)
        {
            diff = case1;
        }
        if (case2 < diff)
        {
            diff = case2;
        }

        for(int i = 1; i<n-1; i++){
            for(int j = 1; j<n-1-i; j++){
                int temp = abs(left[j] - right[i]);
                if(temp < diff){
                    diff =temp;
                }
                if(left[j]>right[i])
                    break;
            }
        }
        // cout << "LEFT : " << endl;

        // for(int i = 0;i<n; i++){
        //     cout << left[i] << " ";
        // }
        // cout << endl << endl;

        // cout << "RIGHT : " << endl;
        
        // for(int i = 0; i<n; i++){
        //     cout << right[i] << " " ;
        // }
        // cout << endl << endl;
        cout << diff << endl;
    }
}
