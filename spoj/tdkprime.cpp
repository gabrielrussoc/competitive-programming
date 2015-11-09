#include <bits/stdc++.h>
using namespace std;

const int N = 86100007;
unsigned int p[2690639], x = 0;
int v[5000005];

void crivo(){
    for(unsigned int i = 2; i*i < N; i++){
        if(!(p[i>>5] & (1<<(i&(1<<6)-1)))){
            for(unsigned int j = i*i; j < N; j += i)
                p[j>>5] |= (1<<(j&(1<<6)-1));
        }
    } 
    for(unsigned int i = 2; i < N; i++){
        if(!(p[i>>5] & (1<<(i&(1<<6)-1)))) v[x++] = i;
        if(x > 5000000) break;
    }
}

int main(){
    int q;
    crivo();
    scanf("%d",&q);
    while(q--){
        int k;
        scanf("%d",&k);
        printf("%d\n",v[k-1]);
    }
}
