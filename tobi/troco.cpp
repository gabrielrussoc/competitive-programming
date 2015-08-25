#include <cstdio>
#define MAXN 100005
using namespace std;


int v,m;
int d[MAXN],p[MAXN];

int main(){

    scanf("%d %d",&v,&m);
    for(int i = 0; i < m; i++)
        scanf("%d",&d[i]);
    
    for(int i = 1; i < MAXN; i++)
        p[i] = 0;
    p[0] = 1;

    
    for(int i = 0; i < m; i++){
        for(int j = v; j >= d[i]; j--)
            if(p[j-d[i]] == 1)
                p[j] = 1;
    }


    if(p[v]) printf("S\n");
    else printf("N\n");

}
