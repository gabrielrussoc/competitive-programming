#include <cstdio>
#include <cstring>

using namespace std;


int in[55][55], out[55][55], tmp[55][55];
int M,n;
const int MODN = 1000000007;

void clear(){
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            tmp[i][j] = 0;
}
void update(){
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            out[i][j] = tmp[i][j];
}

void mult() {
    clear();
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            for(int k = 0; k < M; k++)
                tmp[i][j] += (out[i][k] * in[k][j])%MODN;
    update();
}

void quad() {
    clear();
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            for(int k = 0; k < M; k++)
                tmp[i][j] += (out[i][k] * out[k][j])%MODN;
    update();
}

void solve(){
    while(n){
        if(n&1){
            mult();
            n--;
        }
        else{
            quad();
            n /= 2;
        }
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&M,&n);
        for(int i = 0; i < M; i++){
            for(int j = 0; j < M; j++){
                scanf("%d",&in[i][j]);
                out[i][j] = (i==j);
            }
        }
        solve();
        for(int i = 0; i < M; i++)
            for(int j = 0; j < M; j++)
                printf("%d%c",out[i][j],j == M-1 ? '\n' : ' ');
    }
}