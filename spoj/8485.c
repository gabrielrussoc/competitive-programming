#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1005

int v[MAX][MAX],aux[MAX][MAX],tam[MAX];

int main(){

    int i,j,m,n,q,k,l,u,res,a,b,hi,lo,mid;
    
	while(scanf("%d %d",&n,&m) && n != 0 && m != 0){
        for(i = 0; i < n; i++){
    		for(j = 0; j < m; j++)
        		scanf("%d",&v[i][j]);
        }

        scanf("%d",&q);
           
        for(k = 0; k < q; k++){
            scanf("%d %d",&l,&u);
            res = 0;        

            for(i = 0; i < n+m-1; i++){
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

