#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int v[44];
    int f[44];
    while(scanf("%d",&n) != EOF){
        int x;
        for(int i = 0; i < n; i++){
            scanf("%d",&x);
            v[x] = i;
        }
        for(int i = 0; i < n; i++)
            scanf("%d",f+i);

        int ans = 0;
        for(int i = 0; i < n; i++){
            x = v[f[i]];
            for(int j = i+1; j < n; j++){
                if(v[f[j]] < x) ans++;
            }
        }
        printf("%d\n",ans);

    }
}
