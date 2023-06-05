#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--){
        int x,k;
        cin >> x >> k;

        int min_num = x;
        int max_num = x*k;

        int first_multiple = x * 2;

        int least_lcm, max_lcm;
        max_lcm = max_num * (max_num-1);
        if(first_multiple <= max_num){
            least_lcm = first_multiple;
        }
        else{
            least_lcm = (min_num+1) * min_num;
        }
        cout << least_lcm << " " << max_lcm << endl;
    }
}
