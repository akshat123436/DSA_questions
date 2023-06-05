#include <stdio.h>

int main(){
    int n, ans = 0, final = 0;
    scanf("%d",&n);

    int x[n],y[n];

    for(int i = 0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
    }

    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            ans = 0;
            for(int k = 0;k<n;k++){
                float var=(y[j]-y[i]) * 1.0 /(x[j]-x[i]);
                if (y[k] != var * (x[k] - x[i]) + y[i])
                    ans++;
                 
            }
            if (final < ans )
                final = ans;
        }
    }

    printf("%d\n", ans);

}