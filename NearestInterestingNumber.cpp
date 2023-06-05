#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define ll long long
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
           int n,x;
        cin>>n;
        int num = n;
        int sum = 0;
        for(int i=n ; i<=2000 ; i++)
        {
            sum = 0;
            int k =i;
            while(k>0)
            {
                x = k%10;
                sum = sum+x;
                k = k/10;
            }
          //  cout<<sum<<endl;
           // cout<<i<<endl;
            if(sum%4 == 0)
            {
                cout<<i<<endl;
                break;
 
            }
 
        }
 
    return 0;
}