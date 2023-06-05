#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int32_t main(){
    int T;
    cin >> T;

    while(T--){
        int n1, n2, n3;

        cin >> n1 >> n2 >> n3;

        bool cond = false;

        if(n1 == 7 || n2 == 7 || n3 == 7)
            cond = true;
        if(cond)
            cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
