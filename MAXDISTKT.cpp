#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int32_t main(){
    // ios_base :: sync_with_stdio(0);
    // cin.tie(NULL);

    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        int arr[n], sortedarr[n];

        int max = INT_MIN;

        for(int i = 0 ;i<n;i++){
            cin >> arr[i];
            sortedarr[i] = arr[i];
            if(arr[i] > max)
                max = arr[i];
        }

        sort(sortedarr, sortedarr+n, greater<int>());

        int start = max-1;
        // cout << "max : " << max << endl;
        map <int, vector<int>> corresponding_numbers;
        int j;
        for(j = 0 ;j<n ;j++){
            // cout << start << endl;
            if(start <= 0){
                break;
            }
            // cout << "start before : " << start << endl;
            if(start<=(sortedarr[j]-1)){
                // cout << "start after : " << start << endl;
                corresponding_numbers[sortedarr[j]].push_back(start);
                start--;
            }
            else{
                // cout << "start after : " << start << endl;
                start = sortedarr[j]-1;
                corresponding_numbers[sortedarr[j]].push_back(start);
                start--;
            }
        }

        for(;j<n;j++){
            corresponding_numbers[sortedarr[j]].push_back(0);
        }
    // cout << endl << endl;
        for(int i = 0;i<n; i++){
            cout << corresponding_numbers[arr[i]].back() << " ";
            corresponding_numbers[arr[i]].pop_back();
        }
        cout << endl;
    }
}
