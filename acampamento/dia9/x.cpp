#include <cstdio>

using namespace std;

int main(){
    
    char m[307][307];
    int n;
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf(" %c",&m[i][j]);


    bool ans = true;
    char tgt = m[0][0];
    char tgt1 = m[0][1];
    if(tgt == tgt1){
        printf("NO\n");
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j || i+j == n-1){
                if(m[i][j] != tgt) 
                    ans = false;
            }
            else{
                if(m[i][j] != tgt1)
                    ans = false;
            }
        }
    }

    if(ans)
        printf("YES\n");
    else
        printf("NO\n");



}
