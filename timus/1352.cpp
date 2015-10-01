#include <bits/stdc++.h>
using namespace std;
const int N = 7000000;

int ms[] = {0,2,3, 0, 0, 0, 0, 0, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593};

bool ll (int n){
    long long cont = 0, s = 4, mp = (1<<n)-1;
    for(int i = 2; i*i<= n; i++)
        if(n%i == 0) cont++;
    if(cont != 0) return false;
    for(int i = 0; i < n-2; i++)
        s = ((s*s) -2)%mp;
    return s==0;
}

int main(){
    int k = 3;
    for(int i = 4; i < 31; i++){
        if(ll(i)){
            ms[k++] = i;
        }
    }
    int t,q;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        scanf("%d",&q);
        printf("%d\n",ms[q]);
    }
}
