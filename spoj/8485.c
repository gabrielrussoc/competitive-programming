#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 505

int v[MAX][MAX];

int buscab(int i,int j,int lo, int hi,int p){
    int mid = (lo+hi)/2;

    if(hi == lo){
        if(v[i+mid][j+mid] >= p) return mid;
        else return -1; 
    }   

    if(v[i+mid][j+mid] >= p)
        return buscab(i,j,mid,hi,p);
    else return buscab(i,j,mid+1,hi,p);

}

int main(){

    int i,j,m,n,q,k,l,u,res,hi,baixo,alto;
    
	while(scanf("%d %d",&n,&m) && n != 0){
        for(i = 0; i < n; i++){
    		for(j = 0; j < m; j++)
        		scanf("%d",&v[i][j]);
        }
        
        scanf("%d",&q);
       
        for(k = 0; k < q; k++){
            scanf("%d %d",&l,&u);
    
            res = 0;

            for(i = 0; i < n; i++){
                
                for(hi = 0; hi < MAX; hi++){
                    if(i + hi == n - 1 || hi == m-1)
                        break; 
                }

                baixo = buscab(i,0,0,hi,l);
                alto = buscab(i,0,0,hi,u) - 1;
                if(baixo >= 0 && alto >= 0){
                    if(abs(i+baixo - j+alto) > res)
                        res = i+baixo - j + alto;
                }
            }
            for(j = 0; j < m; j++){
                for(hi = 0; hi < MAX; hi++){
                    if(j + hi == m - 1 || hi == n - 1)
                        break;
                }
                
                baixo = buscab(0,j,0,hi,l);
                alto = buscab(0,j,0,hi,u) - 1;
                if(baixo >= 0 && alto >= 0){
                    if(abs(i+baixo - j + alto) > res)
                        res = i + baixo - j + alto;
                }
            }

            printf("%d\n",res);
        } 
        printf("-\n");
	}
    
    return 0;
}

