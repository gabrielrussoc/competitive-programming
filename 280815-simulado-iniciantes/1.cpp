#include <cstdio>
#include <algorithm>

using namespace std;

int t;
int v[1234];

void update(){
    int aux = v[0];
    for(int i = 0; i < t-1; i++)
        v[i] = v[i+1];
    v[t-1] = aux;

}

void priori(int a){
    int j = t-1;
    for(int i = 0; i < t; i++)
        if(v[i] == a) j = i;

    for(int i = j; i > 0; i--)
        v[i] = v[i-1];
    v[0] = a;

}

int main(){

    int p, c, tc = 1;
    while(scanf("%d %d",&p,&c) && p != 0 && c != 0){
    t = min(1000,p);
    for(int i = 0; i < t; i++)
        v[i] = i+1;
    
    char coma;
    printf("Case %d:\n",tc++);
    for(int i = 0; i < c; i++){
        scanf(" %c",&coma);
        int pri;
        if(coma == 'E'){
            scanf("%d",&pri);
            priori(pri);
        }
        else {
            printf("%d\n",v[0]);
            update();
        }
    }
    }
    
}
