#include <cstdio>
#include <cstring>
typedef long long num;
using namespace std;


int M,n;
const int MODN = 1000000007;

struct Matrix {
    num v[55][55];
};

Matrix I, O, in,ans;

void mult(Matrix &x, Matrix &y){
    Matrix t = O;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < M; j++)
            for(int k = 0; k < M; k++){
                t.v[i][j] += (x.v[i][k] * y.v[k][j])%MODN;
                t.v[i][j] %= MODN;
            }

    x = t;
}

Matrix solve(){
    
    Matrix x = I;
    Matrix y = in;
    
    while(n){
        if(n%2 == 1)
            mult(x,y);
        mult(y,y);
        n /= 2;
    }
    return x;
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&M,&n);
        for(int i = 0; i < M; i++){
            for(int j = 0; j < M; j++){
                scanf("%lld",&in.v[i][j]);
                I.v[i][j] = (i==j);
                O.v[i][j] = 0;
                
            }
        }
        ans = solve();
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < M; j++) {
                printf("%lld ",ans.v[i][j]);    
            }
            printf("\n");
        }
            
    }
}
