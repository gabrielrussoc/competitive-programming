#include <bits/stdc++.h>
#define MAXN 30004

using namespace std;

int v[MAXN],aux[MAXN];

int main(){

    int n;
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
        scanf("%d",&v[i]);

    int q;
    scanf("%d",&q);

    while(q--){
        int i, j, k;
        scanf("%d %d %d",&i,&j,&k);
        
        int cont = 0;
        for(int w = i-1; w < j; w++){
            if(v[w] > k)
                cont++;
        }

        printf("%d\n",cont);
    }

}
