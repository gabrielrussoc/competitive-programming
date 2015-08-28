#include <cstdio>
#include <algorithm>

using namespace std;

int freq[105];

int main(){
    int a,v;
    int tc = 1;
    while(scanf("%d %d",&a,&v) && a != 0 && v != 0){
        for(int i = 0; i < a; i++)
            freq[i] = 0;
        int maxi = 0;
        int x,y;
        for(int i = 0; i < v; i++){ 
            scanf("%d %d",&x,&y);
            x--; y--;
            freq[x]++;
            maxi = max(freq[x],maxi);
            freq[y]++;
            maxi = max(freq[y],maxi);
        }
        printf("Teste %d\n",tc++);
        for(int i = 0; i < a; i++)
            if(freq[i] == maxi) printf("%d ",i+1);
        printf("\n\n");
    }

}