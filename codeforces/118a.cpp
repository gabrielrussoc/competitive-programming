#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>

int vowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') return 1;
    return 0;
}

int main(){

    char s[105];
    scanf("%s",s);
    int t = strlen(s);
    for(int i = 0; i < t; i++){
        s[i] = tolower(s[i]);
        if(vowel(s[i])) s[i] = '_';
    }
    char r[205];
    int k = 0;
    for(int i = 0; i < t; i++)
        if(s[i] != '_'){
            r[k++] = '.';
            r[k++] = s[i];
        }
    r[k] = '\0';
    printf("%s\n",r);

}
