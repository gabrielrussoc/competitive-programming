#include <cstdio>

using namespace std;

int v[100005];

void div(int i){
    while(v[i] % 2 == 0) v[i] /= 2;
    while(v[i] % 3 == 0) v[i] /= 3;
}

int main(){
    
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",v+i);

    div(0);
    int k = v[0];
    for(int i = 1; i < n; i++){
        div(i);
        if(v[i] != k) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}