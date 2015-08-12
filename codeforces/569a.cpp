#include <cstdio>

using namespace std;

int main(){
    int T, S, q;
    scanf("%d %d %d",&T,&S,&q);
    int ans = 1;
    int listen,down;
    listen = 0;
    down = S;

    while(down < T) {
        down += q-1;
        listen += q;
        if(down >= T)
            break;
        if(listen >= down){
            ans++;
            listen = listen-down;
        }
    }
    printf("%d\n",ans);
}