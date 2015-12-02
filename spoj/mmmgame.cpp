#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int ans = 0;
        int x, xablau = 1;
        for(int i = 0; i < n; i++){
            scanf("%d",&x); 
            if(x!=1) xablau = 0;
            ans ^= x;
        }
        if(xablau){
            if(n&1) puts("Brother");
            else puts("John");
        }
        else {
            if(!ans) puts("Brother");
            else puts("John");
        }
    }

}
