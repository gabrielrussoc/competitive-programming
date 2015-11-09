#include <bits/stdc++.h>

bool isPal(int n){
    char s[12];
    sprintf(s,"%d",n);
    int k = strlen(s);
    for(int i = 0; i < k/2; i++)
        if(s[i] != s[k-i-1]) return false;
    return true;
}

int main(){
    int ans = 0;
    for(int i = 100; i < 1000; i++)
        for(int j = i; j < 1000; j++){
            if(isPal(i*j) && i*j > ans) ans = i*j;
        }
    printf("%d\n",ans);

}
