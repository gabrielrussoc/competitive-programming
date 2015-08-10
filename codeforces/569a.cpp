#include <cstdio>

using namespace std;

int main(){
    int T, S, q;
    scanf("%d %d %d",&T,&S,&q);
    double taxa = q*(q-1);
    double ouvi,baixou, aux;
    int ans = 1;
    baixou = S;

    while(1) {
        ouvi = taxa*baixou;
        if(ouvi >= T) break;
        ans++;
        baixou = ouvi;
    }
    printf("%d\n",ans);
}