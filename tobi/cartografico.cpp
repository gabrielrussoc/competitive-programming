#include <queue>
#include <cstdio>
#include <vector>
#include <climits>
#include <cstring>
#define pb push_back
const int N = 1000006;

using namespace std;

int n;
int maxi, ind;
int vhead[N], to[2*N], next[2*N], es;


void dfs(int v, int pai, int d){
    if(d > maxi) maxi = d, ind = v;
    for(int e = vhead[v]; e> 0; e = next[e])
        if(to[e] != pai) dfs(to[e],v,d+1);
}


int main(){
    int a,b;
    es = 1;
    scanf("%d",&n);
    for(int i = 0; i < n-1; i++){
        scanf("%d %d",&a,&b);
        to[es] = b;
        next[es] = vhead[a];
        vhead[a] = es++;

        to[es] = a;
        next[es] = vhead[b];
        vhead[b] = es++;
    }
    maxi = 0;
    dfs(1,-1,0);
    maxi = 0;
    dfs(ind,-1,0);
    printf("%d\n",maxi);     
}
