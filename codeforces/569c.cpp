#include <cstdio>
#include <cstring>
#include <string>
#define MAXN 10000007
#define eps 1e-8

using namespace std;

int primo[MAXN], accprimo[MAXN], accpalin[MAXN], palin[MAXN];

void crivo(int n) {
    for(int i = 2; i*i <= n; i++){
        if(!primo[i]){
            for(int j = i*i; j <= n; j += i){
                primo[j] = 1;
            }
        }
    }
}

void ispalin(int n) {

    for(int i = 1; i <= n; i++) {
        int aux = i;
        int k = 0;
        while(aux) {
            k++;
            aux /= 10;
        }
        int pot = 1;
        while(--k) {
            pot *= 10;
        }
        aux = i;
        int inv = 0;
        while(aux) {
            inv += pot*(aux%10);
            pot /= 10;
            aux /= 10;
        }

        
        if(i == inv)
            palin[i] = 1;
    }



}

int main(){
    
    memset(primo,0,sizeof primo);
    memset(palin,0,sizeof palin);
    crivo(MAXN);
    ispalin(MAXN);

    int p,q;
    scanf("%d %d",&p,&q);
    double A = (double)p/q;

    accprimo[1] = 0;
    accpalin[1] = 1;
    for(int i = 2; i < MAXN; i++){
        accprimo[i] = accprimo[i-1];
        accpalin[i] = accpalin[i-1];
        if(!primo[i])
            accprimo[i]++;
        if(palin[i])
            accpalin[i]++;
    }

    int n = 0;
    for(int i = 1; i < MAXN; i++) {
        if((double) (accprimo[i] - A*accpalin[i]) <= eps)
            n = i;
    }

    if(n == 0)
        printf("Palindromic tree is better than splay tree\n");
    else
        printf("%d\n",n);




}