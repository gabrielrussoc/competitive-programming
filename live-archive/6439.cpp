#include <bits/stdc++.h>
#define MAX 50004
using namespace std;
typedef unsigned long long hash;

hash x[MAX];
hash h[MAX];
const hash X = 33;

int cv(char a){
    return (a-'A');
}

hash calc(int i, int j){
    return (h[j] - h[i-1]*x[j-i+1]);
}

int solve(int i, int j){
    if(i > j) return 0;
    for(int k = i; k < (i+j+1)/2; k++){
        if(calc(i,k) == calc(j-k+i,j)) return 2 + solve(k+1,j-k+i-1);
    }
    return 1;
}

int main(){
    x[0] = 1;
    for(int i = 1; i < MAX; i++)
        x[i] = X*x[i-1];
    int t;
    scanf("%d",&t);
    int tc = 1;
    while(t--){
        char s[MAX];
        scanf(" %s",s);
        int k = strlen(s);
        h[0] = cv(s[0]);
        for(int i = 1; i < k; i++){
            h[i] = h[i-1] * X + cv(s[i]);
        }
        int ans = solve(0,k-1);
        printf("Case #%d: %d\n",tc++,ans);   
    }
 
}
