#include <cstring>
#include <cstdio>
#include <ctype.h>

int main(){

    char s[105],t[105];
    scanf("%s %s",s,t);
    int k = strlen(s);
    for(int i = 0; i < k; i++){
        s[i] = tolower(s[i]);
        t[i] = tolower(t[i]);
    }
    if(strcmp(s,t) < 0) printf("-1\n");
    else if (strcmp(s,t) == 0) printf("0\n");
    else printf("1\n");

}
