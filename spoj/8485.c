#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1005

int v[MAX][MAX],aux[MAX][MAX],tam[MAX];

/*int busca1(int i, int lo, int hi, int l){
    int mid = (lo+hi)/2;

    if(lo == hi){
        if(aux[i][mid] >= l) return lo;
        else return -1;
    }
        
    if(aux[i][mid] >= l)
        return busca1(i,lo,mid,l);
    else
        return busca1(i,mid+1,hi,l);

}

int busca2(int i, int lo, int hi, int u){
    int mid = (lo+hi+1)/2;


    if(lo == hi){
        if(aux[i][mid] <= u) return lo;
        else return -1;
    }
    if(aux[i][mid] <= u)
        return busca2(i,mid,hi,u);
    else
        return busca2(i,lo,mid-1,u);

}*/

int main(){

    int i,j,m,n,q,k,l,u,res,x,y,z,p,a,b,hi,lo,mid;
    
	while(scanf("%d %d",&n,&m) && n != 0 && m != 0){
        for(i = 0; i < n; i++){
    		for(j = 0; j < m; j++)
        		scanf("%d",&v[i][j]);
        }

        if(n > m)
            p = n;
        else
            p = m;

        for(x = 0; x < n + m - 1; x++){
            if(x < p)
                z = 0;
            else
                z = x - p + 1;

            i = 0;
            for(y = z; y <= x - z; y++){
                if((n-1-x+y < n && n-1-x+y >= 0) && (y >= 0 && y < m)){
                    aux[x][i] = v[(n-1-x+y)][y];
                    i++;
                }
            }
            tam[x] = i;
        } 

        scanf("%d",&q);
           
        for(k = 0; k < q; k++){
            scanf("%d %d",&l,&u);
            res = 0;        

            for(i = 0; i < n+m-1; i++){
                /*a = busca1(i,0,tam[i]-1,l);*/

                lo = 0;
                hi = tam[i]-1;
                while(hi != lo){
                    mid = (hi + lo)/2;

                    if(aux[i][mid] >= l)
                        hi = mid;
                    else
                        lo = mid+1;
                }
                a = lo;

                if(aux[i][a] >= l){
                    /*b = busca2(i,0,tam[i]-1,u);*/
                    lo = 0;
                    hi = tam[i]-1;

                    while(hi != lo){
                        mid = (hi + lo+1)/2;

                        if(aux[i][mid] <= u)
                            lo = mid;
                        else
                            hi = mid-1;
                    }

                    b = lo;

                    if(aux[i][b] <= u && b >= a)
                        if(b-a+1 > res)
                            res = b-a+1;
                }

            }       
                
            printf("%d\n",res);
            
    	}

        printf("-\n");
    }
    
    return 0;
}

