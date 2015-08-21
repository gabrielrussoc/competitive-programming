#include <cstdio>
#include <cstring>

using namespace std;

int n,m;

struct peca {
    int x,y,t;
}v[1004];

int tab[1003][1003];

void expand(peca k){

    if(k.t == 0){
        int i, j;
        i = k.x;
        j = k.y+1;
        while(j < m && tab[i][j] != -1)
            tab[i][j++] = 1;
        j = k.y-1;
        while(j >= 0 && tab[i][j] != -1)
            tab[i][j--] = 1;        
        i = k.x+1;
        j = k.y;
        while(i < n && tab[i][j] != -1)
            tab[i++][j] = 1;
        i = k.x-1;
        while(i >= 0 && tab[i][j] != -1)
            tab[i--][j] = 1;

        i = k.x-1;
        j = k.y+1;
        while(j < m && i >= 0 && tab[i][j] != -1)
            tab[i--][j++] = 1;
        i = k.x + 1;
        j = k.y - 1;
        while(i < n  && j >= 0 && tab[i][j] != -1)
            tab[i++][j--] = 1;

        i = k.x-1;
        j = k.y-1;
        while(i >= 0 && j >= 0 && tab[i][j] != -1)
            tab[i--][j--] = 1;
        i = k.x+1;
        j = k.y+1;
        while(i < n && j < m && tab[i][j] != -1)
            tab[i++][j++] = 1; 
    }

    else if(k.t == 1){
        int i, j;
        i = k.x;
        j = k.y;
        if(i+2 < n && j+1 < m && tab[i+2][j+1] != -1){
            tab[i+2][j+1] = 1;
        }
        if(i+2 < n && j-1 >= 0 && tab[i+2][j-1] != -1){
            tab[i+2][j-1] = 1;
        }
        if(i+1 < n && j+2 < m && tab[i+1][j+2] != -1){
            tab[i+1][j+2] = 1;
        }
        if(i+1 < n && j-2 >= 0 && tab[i+1][j-2] != -1){
            tab[i+1][j-2] = 1;
        }
        if(i-1 >= 0 && j+2 < m && tab[i-1][j+2] != -1){
            tab[i-1][j+2] = 1;
        }
        if(i-1 >= 0 && j-2 >= 0 && tab[i-1][j-2] != -1){
            tab[i-1][j-2] = 1;
        }
        if(i-2 >= 0 && j+1 < m && tab[i-2][j+1] != -1){
            tab[i-2][j+1] = 1;
        }
        if(i-2 >= 0 && j-1 >= 0 && tab[i-2][j-1] != -1){
            tab[i-2][j-1] = 1;
        }       
    }
    else return;
}

int main(){

    int tc = 1;
    while(scanf("%d %d",&n,&m), n != 0){
        memset(tab,0,sizeof tab);
        int a, k = 0;
        for(int i = 0; i < 3; i++){
            scanf("%d",&a);
            for(int j = 0; j < a; j++){
                scanf("%d %d",&v[k].x,&v[k].y);
                v[k].x--;
                v[k].y--;
                v[k].t = i;
                tab[v[k].x][v[k].y] = -1;
                k++;
            } 
        }
        
        for(int i = 0; i < k; i++){
            expand(v[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(tab[i][j] == 0) ans++;
        
        printf("Board %d has %d safe squares.\n",tc++,ans); 
        }
}
