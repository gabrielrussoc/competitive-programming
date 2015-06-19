#include <cstdio>
#include <queue>
#include <climits>
#include <cstdlib>

using namespace std;

int main(){

    int c, n;
    int atd[10];
    scanf("%d %d",&c,&n);
    int t,d;
    int ans = 0;
    int ind;

    for(int i = 0; i < n; i++){
        scanf("%d %d",&t,&d);
        if(i < c)
            atd[i] = d+t;
        else{
            int min = 999;
            for(int j = 0; j < c; j++){
                if(atd[j] < min){
                    min = atd[j];
                    ind = j;
                }
            }
            if(min - t > 20)
                ans++;
            atd[ind] = d+max(min,t);
        }
    }
    printf("%d\n",ans);

}
