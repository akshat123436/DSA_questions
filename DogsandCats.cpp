#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int j = 1; j<= T; j++){
        int N, D, C , M;

        cin >> N >> D >> C >> M;

        string s;
        cin >> s;

        int dogs, cats;
        dogs = cats = 0;
        int length = s.length();
        for(int i = 0 ;i<length;i++){
            if(s[i] == 'C')
                cats++;
            else dogs++;
        }
        bool breaking_condition =false;
        int dogsFed = 0;
        for(int i = 0 ;i<length;i++){
            if(s[i] == 'C' && C>0){
                C--;
            }
            else if(s[i] == 'D' && D>0){
                C+=M;
                D--;
                dogsFed++;
            }
            else{
                break;
            }
        }

        if(dogsFed == dogs){
            cout << "Case #" << j << ": YES";
        }
        else{
            
            cout << "Case #" << j << ": NO";
        
        }
        cout << endl;
    }
}
