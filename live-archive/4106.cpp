#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int v[2010][2010];
int m[2010][2010][2][2];

int t,h,f;


int pd(int a, int h1,int s, int d){

    //d 0 esquerda, 1 direita
    //s 0 come, 1 nao come

    if(a >= t || a < 0) return 0;
    if(h1 < 0) return 0;
    if(m[a][h1][s][d] != -1) return m[a][h1][s][d];
  
    int ans;

    if(s == 0)
        ans = v[a][h1] + max(max(pd(a,h1-1,0,0),pd(a+1,h1,1,0)),pd(a-1,h1,1,1));
    else{
        if(d == 0)
            ans = max(pd(a+1,h1,1,0),pd(a,h1-f,0,0));
        else
            ans = max(pd(a-1,h1,1,1),pd(a,h1-f,0,0));    
    }
        

    m[a][h1][s][d] = ans;
    return ans;
}



int main(){

    int c;
    scanf("%d",&c);
    while(c--){
        memset(v,0,sizeof v);
        for(int i = 0; i < 2003; i++)
            for(int j = 0; j < 2003; j++)
                for(int ii = 0; ii < 2; ii++)
                    for(int jj = 0; jj < 2; jj++)
                        m[i][j][ii][jj] = -1;
        scanf("%d %d %d",&t,&h,&f);
        int sum = 0;
        for(int i = 0; i < t; i++){
            int a;
            scanf("%d",&a);
            sum += a;
            for(int j = 0; j < a; j++){
                int n;
                scanf("%d",&n);
                v[i][n]++; 
            }
        }
        int ans = -1;
        if(f == 0)
            ans = sum;
        else
            for(int i = 0; i < t; i++)
                ans = max(ans,pd(i,h,0,0));
        
        printf("%d\n",ans);
    }

}
