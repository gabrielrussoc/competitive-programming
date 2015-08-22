#include <cstdio>
#define MAXN 100005

using namespace std;

int a[MAXN], b[MAXN];

int main(){
    int na,nb;
    int k,m;
    scanf("%d %d",&na,&nb);
    scanf("%d %d",&k,&m);

    for(int i = 0; i < na; i++)
        scanf("%d",&a[i]);
    for(int i = 0; i < nb; i++)
        scanf("%d",&b[i]);

    if(a[k-1] < b[nb-m])
        printf("YES\n");
    else
        printf("NO\n");

}
