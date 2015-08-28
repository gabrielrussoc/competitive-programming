#include <cstdio>

using namespace std;

int m[10][10];

bool pode(int i, int j, int k) { 
    
    //printf("%d %d\n",i,j);
    for(int p = 0; p < 9; p++)
        if(m[i][p] == k || m[p][j] == k) return false;

    int x,y;
    x = i/3, y = j/3;

    x *= 3;
    y *= 3;

    for(int l = x; l < x+3; l++)
        for(int c = y; c < y+3; c++)
            if(m[l][c] == k) return false;

    return true;
}

void show(){
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++)
            printf("%d",m[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool solve(int i, int j){ 
    if(i == 9) {
        //printf("\n\noi------------------\n\n\n");
        //show();
        return true;
    }
    bool ans = false;
    if(m[i][j] != 0) {
        if(j == 8)
            ans = solve(i+1,0);
        else
            ans = solve(i,j+1);
    }    
    else{
    for(int k = 1; k <= 9; k++){
        if(pode(i,j,k)) {
            m[i][j] = k;
            if(j == 8)
                ans = solve(i+1,0);
            else
                ans = solve(i,j+1);
            if(ans) return true;
            else m[i][j] = 0;
        }
    }
    }
    return ans;
}

int main(){

    int t;
    char c;
    scanf("%d",&t);
    while(t--){
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++){
                scanf(" %c",&c);
                m[i][j] = c-'0';
            }

        //show();

        bool ans = solve(0,0);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++)
                printf("%d",m[i][j]);
            printf("\n");
        }
    }

}
