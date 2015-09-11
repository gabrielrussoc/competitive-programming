#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 1000017

using namespace std;

int p[MAXN];
int v[MAXN];
int gemeo[MAXN];
int acc[MAXN];

int k = 0;
void crivo(int n){
    for(int i = 2; i*i <= n; i++){
        if(!p[i]){
            for(int j = i*i; j <= n; j+= i){
                p[j] = 1;
            }
        }
    }
    for(int i = 2; i <= n; i++)
        if(!p[i]) v[k++] = i;
}

int main(){
    memset(p,0,sizeof p);
    memset(gemeo,0,sizeof gemeo);
    crivo(MAXN-1);
    for(int i = 1; i < k; i++){
        if(v[i] - v[i-1] == 2) gemeo[v[i]]++, gemeo[v[i-1]]++;
    }
    acc[0] = 0;
    for(int i = 1; i < MAXN; i++){
        acc[i] = acc[i-1]; 
        if(gemeo[i]) {
            acc[i]++;
        }
    }
    int q;
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(x > y) swap(x,y);
        printf("%d\n",acc[y]-acc[x-1]);
    }
}
