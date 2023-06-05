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
        int n, k;
        cin >> n >> k;

        int below = n - k;

        int wins = below * k;

        wins += k *(k-1)/2;

        int min_team_wins = wins/k;

        cout << min_team_wins * 2 << endl;

    }
}
