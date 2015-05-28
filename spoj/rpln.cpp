#include <bits/stdc++.h>
#define N 400005

using namespace std;

int tree[N], input[N];

int func(int k, int ini, int fim, int l, int r){
    
    if(ini >= l && fim <= r)
        return tree[k];
    
    if(ini > r || fim < l)
        return INT_MAX;
        
    else {
        int mid = (ini + fim)/2;
        return min( func(2*k,ini,mid,l,r) , func(2*k+1,mid+1,fim,l,r) );
    }
    
}

void insert(int i, int k, int ini, int fim){
    
    int mid = (ini + fim)/2;
    
    if(ini == fim)
        tree[k] = input[i];
        
    else{
        if(mid >= i)
            insert(i, 2*k, ini, mid);
        else
            insert(i, 2*k+1, mid+1, fim);
            
        tree[k] = min(tree[2*k], tree[2*k + 1]);
    }
    
    
    
}

int main(){

    int t, q, n, a, b;
    
    scanf("%d",&t);
    
    int j = 0;
    
    while(j < t){
        
        scanf("%d %d",&n,&q);
        
        for(int i = 0; i < n; i++){
            scanf("%d",&input[i]);
            insert(i,1,0,n-1);
        }
            
        printf("Scenario #%d:\n",j+1);
            
        for(int i = 0; i < q; i++){
            scanf("%d %d",&a,&b);
            
            int ans = func(1,0,n-1,a-1,b-1);
            
            printf("%d\n",ans);
            
            
        }
            
        j++;
    }

}