#include <cstdio>
#include <cstring>

char c[105];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s",c);
        int t = strlen(c);
        if(t > 10) printf("%c%d%c\n",c[0],t-2,c[t-1]);
        else printf("%s\n",c);
    }
}
