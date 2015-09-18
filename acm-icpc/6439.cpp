#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long hash;

hash x[50004];
hash h[50004];
const hash X = 33;

int cv(char a){
    return (a-'A');
}

hash calc(int i, int j){
    return (h[i+1] - h[j]*x[j-i+1]);
}

int solve(int j, int t){
    if(t == 0) return 0;
    for(int i = j; i < t; i++){
        if(calc(j,i) == calc(i+t-(j-i+1),j+t-1)) return 1 + solve(i+1,j-i+1);
    }
    return 1;
}

int main(){
    x[0] = 1;
    for(int i = 1; i < 50004; i++)
        x[i] = X*x[i-1];
    int t;
    scanf("%d",&t);
    while(t--){
        char s[50004];
        scanf(" %s",s);
        int k = strlen(s);
        h[0] = 1;
        for(int i = 1; i <= k; i++){
            h[i] = h[i-1] * x[i-1] + cv(s[i-1]);
        }
        int ans = solve(0,k);
        printf("%d\n",ans);   
    }
 
}
