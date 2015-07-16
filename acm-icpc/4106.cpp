#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int v[2003][2003];
int m[2003][2003];

int t,h,f;


int pd(int a, int h1){

    //printf("Arvore %d, altura %d, qtd %d\n",a,h1,q);

    if(h1 < 0) return 0;
    if(m[a][h1] != -1) return m[a][h1];
  

    int ans = -1;
    for(int i = 0; i < t; i++){
        if(i == a) ans = max(ans, v[a][h1] + pd(a,h1-1));
        else ans = max(ans,v[a][h1] + pd(i,h1-f));
    }

    m[a][h1] = ans;
    return ans;
}



int main(){

    int c;
    scanf("%d",&c);
    while(c--){
        memset(v,0,sizeof v);
        memset(m,-1,sizeof m);
        scanf("%d %d %d",&t,&h,&f);
        for(int i = 0; i < t; i++){
            int a;
            scanf("%d",&a);
            for(int j = 0; j < a; j++){
                int n;
                scanf("%d",&n);
                v[i][n]++; 
            }
        }
        int ans = -1;
        for(int i = 0; i < t; i++){
            ans = max(ans,pd(i,h));
        }
        printf("%d\n",ans);
    }

}
