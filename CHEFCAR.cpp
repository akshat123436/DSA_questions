#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define deb(x) cout << #x << " = " << x << endl
using namespace std;

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, tankCapacity;
        cin >> n >> tankCapacity;

        int distance = n - 1;

        int max = distance * (distance + 1) / 2;

        int min = 0;

        if(tankCapacity >= distance){
            min = distance ;
        }
        else{
            int terms = distance - tankCapacity + 1;
            min = (tankCapacity - 1) + (terms * (terms + 1)/2);
            // deb(terms); deb(distance); deb(tankCapacity); deb(min);
        }

        cout << max << " " << min << endl;
     }
}


// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36