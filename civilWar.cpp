#include <bits/stdc++.h>
using namespace std;

// Driver Code
bool cmp(int a, int b)
{
    return abs(a) > abs(b) || (abs(a) == abs(b) && a > b);
}
int main()
{
    int n;
    cin >> n;
    vector<int> power(n);

    for (int i = 0; i < n; i++)
        cin >> power[i];

    int first = 0;
    int second = 0;

    sort(power.begin(), power.end(), cmp);

    bool turn = true;

    for (int i = 0; i < n; i++)
    {
        if (turn)
        {
            first += power[i];
        }
        else
        {
            second += power[i];
        }
        turn = !turn;
    }

    int diff = abs(first - second);

    cout << diff << endl;
    return 0;
}