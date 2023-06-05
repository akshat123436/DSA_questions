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
        int n[5];

        cin  >> n[0] >> n[1] >> n[2] >> n[3] >> n[4];

        int eng,ind,dra;
        eng = ind =dra = false;

        for(int i = 0 ; i<5 ; i++){
            if(n[i] == 0)
                dra++;
            else if(n[i] == 1)
                ind++;
            else eng++;
        }

        if(eng>ind)
            cout << "ENGLAND";
        else if(ind > eng) cout << "INDIA";
        else cout << "DRAW";
        cout << endl;

    }
}
