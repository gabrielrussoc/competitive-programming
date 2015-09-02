#include <cstdio>

using namespace std;

int v[15];

int sum(int j){
    int ans = 0;
    for(int i = j; i < j+5; i++)
        ans += v[i];

    return ans;
}

int main(){

    int s,d;
    while(scanf("%d %d",&s,&d) != EOF){
        for(int i = 0; i < 12; i++) v[i] = s;


        for(int i = 0; i < 8; i++) {
            int k = i+4;
            while(sum(i) >= 0){    
                v[k--] = -d;
            }   
        }
        int ans = 0;
        for(int i = 0; i < 12; i++)
            ans += v[i];
        if(ans >= 0)
            printf("%d\n",ans);
        else
            printf("Deficit\n");  
    } 
}
