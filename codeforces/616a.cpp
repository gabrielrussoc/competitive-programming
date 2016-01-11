#include <bits/stdc++.h>

const int N = 1e6 + 7;
char a[N], b[N];

int main(){
    int i, j;
    i = j = 0;
    scanf("%s %s",a,b);
    while(a[i] == '0' && a[i+1]) i++;
    while(b[j] == '0' && b[j+1]) j++;
    int p = 0;
    for(int k = i; a[k]; k++) a[p++] = a[k];
    a[p] = 0;
    p = 0;
    for(int k = j; b[k]; k++) b[p++] = b[k];
    b[p] = 0;
    if(strlen(a) > strlen(b)) puts(">");
    else if(strlen(a) < strlen(b)) puts("<");
    else {
        if(strcmp(a,b) > 0) puts(">");
        else if (strcmp(a,b) < 0) puts ("<");
        else puts("=");
    }
}
