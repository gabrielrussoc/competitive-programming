#include <bits/stdc++.h>
using namespace std;

const int N = 2000000;

int p[N];

int main(){
    for(int i = 2; i*i < N; i++){
        if(!p[i]){
            for(int j = i*i; j < N; j += i) p[j] = 1;
        }
    }
    long long ans = 0;
    for(long long i = 2; i < N; i++) if(!p[i]) ans += i;
    printf("%lld\n",ans);
}
