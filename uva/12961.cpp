#include <bits/stdc++.h>
#define N 30004
typedef unsigned long long ll;

using namespace std;

ll v[N];
int n,k;
bool ans;

int main(){

    while(scanf("%d %d",&n,&k) != EOF){
        for(int i = 0; i < n; i++){
            v[i] = 0;
        }
        ans = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                int a;
                scanf("%d",&a);
                v[i] += (1ull << j)*(a%2);
            }
        }
        for(int i = 0; i < k && !ans; i++){
            ll x = 1ull << (k-i-1);
            int j;
            for(j = i; j < n; j++){
                if(x & v[j]){
                    swap(v[j],v[i]);
                    break;
                }
            }
            if(j == n){
                ans = true;
            }
            else{
                for(j = i+1; j < n; j++)
                    if(x & v[j]) v[j] ^= v[i];
            }
        }
        if(!ans && k+1 > n) ans = true;
        if(ans)
            printf("S\n");
        else    
            printf("N\n");
    }
    
}
