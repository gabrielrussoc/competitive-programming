#include <cstdio>
#include <cstring>
#define MAXN 5000005

int p[MAXN];
int memo[MAXN];

void crivo(){
    // p[i] = 0 => prime
    for(int i = 2; i*i < MAXN; i++)
        if(!p[i]){
            for(int j = i*i; j < MAXN; j += i)
                p[j] = i;
        }  
}

int dp(int n){
    if(n == 1) return 0;
    if(!p[n]) return n;
    int &k = memo[n];
    if (k != -1) return k;

    int ans, aux = n;
    while(aux%p[n] == 0) aux /= p[n];
    ans = p[n] + dp(aux);        

    k = ans;
    return k;
}

int main(){
    memset(p,0,sizeof p);
    memset(memo,-1,sizeof memo); 
    crivo();
    
    int a,b;
    while(scanf("%d",&a) && a != 0){
        scanf("%d",&b);
        int cont = 0;
        for(int i = a; i <= b; i++)
            if(!p[dp(i)]) cont++;
        printf("%d\n",cont);
    }

}

