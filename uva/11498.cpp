#include <cstdio>

using namespace std;

int main(){

    int k,n,m;
    while(scanf("%d",&k) && k != 0){
        scanf("%d %d",&n,&m);
        int x,y;
        for(int i = 0; i < k; i++){
            scanf("%d %d",&x,&y);
            if(x == n || y == m)
                printf("divisa\n");
            else if(x >= n && y >= m)
                printf("NE\n");               
            else if(x <= n && y <= m)
                printf("SO\n");               
            else if(x >= n && y <= m)
                printf("SE\n");               
            else
                printf("NO\n");               
        }
    }

}
