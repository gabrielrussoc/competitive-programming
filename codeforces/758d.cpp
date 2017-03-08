#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n;
char k[65];
char s[33];

bool fit(int i, int j) {
    char t[33];
    int p;
    for(p = i; p <= j; p++) t[p-i] = k[p];
    t[p-i] = 0;
    int a = strlen(t);
    int b = strlen(s);
    if(a < b) return true;
    else if (a > b) return false;
    return strcmp(t, s) < 0;
}

ll eval(int i, int j) {
    char t[33];
    int p;
    for(p = i; p <= j; p++) t[p-i] = k[p];
    t[p-i] = 0;
    return atoll(t);
}

int main() {
    scanf("%d",&n);
    scanf(" %s", k);
    sprintf(s, "%d", n);
    int q = strlen(k);
    int i = q-1;
    ll ans = 0;
    ll pot = 1;
    while(i >= 0) {
        int f = i;
        for(int j = i-1; j >= 0; j--) {
            if(!fit(j, i)) break;
            else if(k[j] != '0') f = j;
        } 
        ans += eval(f, i) * pot;
        pot *= ll(n);
        i = f-1;
    }
    printf("%lld\n", ans);
}

