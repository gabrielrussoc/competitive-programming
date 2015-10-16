#include <bits/stdc++.h>
using namespace std;

int v[50],a,d,c,val,b,n;

int main() {
    while(scanf("%d %d",&b,&n) && b != 0){
        memset(v,0,sizeof v);
        for(int i = 0; i < b; i++){
            scanf("%d",&a);
            v[i+1] += a;   
        }
        for(int i = 0; i < n; i++){
            scanf("%d %d %d",&d,&c,&val);
            v[d] -= val;
            v[c] += val;
        }
        bool ans = true;
        for(int i = 1; i <= b; i++)
            if(v[i] < 0) ans = false;
        if(ans) puts("S");
        else puts("N");
    }
}
