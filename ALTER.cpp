#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    
    while(t--){

        int a, b, p, q;
        cin >> a >> b >> p >> q;

        if((p % a == 0) && (q%b == 0)){
            int day1 = p/a;
            int day2 = q/b;

            if(abs(day1 - day2) <= 1){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }
}