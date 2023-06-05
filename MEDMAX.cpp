#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << "," << #y << " = " << y << endl

using namespace std;

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
int total = n * n;
        int arr[total];

        for(int i = 0; i<total ;i++){
            cin >> arr[i];
        }

        sort(arr, arr + total, greater <int> ());
        int ans =0;
        int jumper = n - ceil((double(n) + 1)/2);
        // deb(jumper);
        for(int i = jumper ; i<total ; i++){
            int turns = 0;
            int extra = i-jumper;
            int sum =0;
            int j = i;
            int last = 0;
            for(;j<total && turns < n ;){
                last = j;
                sum += arr[j];
                // deb2(arr[j],j);
                // deb(turns);
                // deb2(extra, jumper);
                if(extra >= jumper){
                    j++;
                    extra -= jumper;
                }
                else{
                    j+= jumper-extra+1;
                    extra = 0;
                }
                
                turns++;
                
            }
            if(turns < n){
                break;
            }
            if(sum < k){
                ans = arr[last];
                break;
            }
        }
        if(ans){
            cout << ans << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}


// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36