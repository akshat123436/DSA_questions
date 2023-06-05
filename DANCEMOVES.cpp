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
        int x, y;
        cin >> x >> y;

        int distance = y-x;

        if(y-x < 0){
            cout << abs(distance) << endl;
        }
        else{
            int moves = distance/2;

            if((distance%2) != 0){
                moves+=2;
            }
            cout << moves << endl;
        }
    }
}
