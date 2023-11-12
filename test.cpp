#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{
    int n;
    vector<vector<int>> edges;

    cin >> n;

    vector<int> indegree(n);

    for(auto &a : edges){
        indegree[a[1]]++;
    }
    int ans = -1;
    for(int i = 0;i<n;i++){
        if(indegree[i] == 0){
            if(ans == -1) ans = i;
            else return -1;
        }
    }

    return ans;
}