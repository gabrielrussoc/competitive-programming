#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int teto(int a, int b){
    if(a%b == 0) return a/b;
    else return (a/b) + 1;
}

int main(){

    int n,x,soma = 0;
    scanf("%d %d",&n,&x);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d",&a);
        soma += a;
    }
    int ans = teto(abs(soma),x);
    printf("%d\n",ans);
}
