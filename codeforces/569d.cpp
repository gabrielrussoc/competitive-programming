#include <cstdio>
#include <iostream>
typedef long long ll;
#define MAXN 4004

using namespace std;

ll comb[MAXN][MAXN], bell[MAXN];
const int MODN = 1000000007;

ll mod(ll n){
    return n%MODN;
}

int main(){

    for(int i = 0; i < MAXN; i++)
        comb[i][0] = 1;

    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j <= i; j++)
            comb[i][j] = mod(comb[i-1][j] + comb[i-1][j-1]);
    } 

    bell[0] = bell[1] = 1;
    for(int i = 2; i < MAXN; i++)
        for(int j = 0; j < i; j++)
            bell[i] = mod(bell[i] + comb[i-1][j]*bell[j]);

    ll n;
    cin >> n;
    ll ans = 0;
    for(int j = 1; j <= n; j++)
        ans = mod(ans + bell[n-j]*comb[n][j]);

    cout << mod(ans) << endl;
}