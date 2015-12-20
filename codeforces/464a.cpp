#include <cstdio>

int main(){
    int n,p;
    char s[1003];

    scanf("%d %d",&n,&p);
    scanf("%s",s);
    for(int i = n-1; i >= 0; i--){
        for(char c = s[i]+1; c < 'a'+p; c++){
            if(i-1 >= 0 && s[i-1] == c) continue;
            if(i-2 >= 0 && s[i-2] == c) continue;
            if(p == 1 && n > 1) continue;
            for(int j = 0; j < i; j++) printf("%c",s[j]);
            s[i] = c;
            printf("%c",s[i]);
            for(int j = i+1; j < n; j++){
                for(char c = 'a'; c < 'a'+p; c++){
                    if(j-1 >= 0 && s[j-1] == c) continue;
                    if(j-2 >= 0 && s[j-2] == c) continue;
                    s[j] = c;
                    break;
                }
                printf("%c",s[j]);
            }
            printf("\n");
            return 0;
        }
    }
    puts("NO");

}
