#include <bits/stdc++.h>
#define MAX 200005

using namespace std;
typedef unsigned long long hash;

const hash X = 33;
hash he[MAX];
hash hd[MAX];
hash x[MAX];
char s[MAX];

hash cv (char c){
    return (c-'a'+1);
}

hash calce(int i, int j){
    return (he[j+1] - he[i]*x[j-i+1]);
}
hash calcd(int i, int j){
    return (hd[j+1] - hd[i]*x[j-i+1]);
}

int main(){
    int n;
    char c;
    scanf("%d",&n);
    for(int i = 1; i < 2*n; i += 2){
        scanf(" %c",&s[i]);
        s[i+1] = 'z'+2;
    }
    s[0] = 'z'+2;
    s[2*n+1] = '\0';
    x[0] = 1;
    he[0] = hd[0] = 0;
    for(int i = 1; i <= 2*n+1; i++){
        x[i] = X*x[i-1];
        he[i] = he[i-1]*X + cv(s[i-1]);
        hd[i] = hd[i-1]*X + cv(s[2*n+1-i]);
    }
    int lo = 1, hi = n;
    while(lo != hi){
        int mid = (lo+hi+1)/2;
        int aux = 2*mid+1;
        int ok = 0;
        for(int i = 0; i <= 2*n+1-aux; i++){
            if(calce(i,i+aux-1) == calcd(2*n-(i+aux-1),2*n-i)){
                ok = 1;
                break;
            }
        }
        if (ok) lo = mid;
        else hi = mid-1;
    }
    printf("%d\n",lo);
}
