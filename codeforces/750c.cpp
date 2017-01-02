#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int inf = INT_MAX;

int main() {
    int n, t, d;
    scanf("%d",&n);
    int acc = 0, maior = -inf, menor = inf;
    for(int i = 0; i < n; i++) {
        scanf("%d %d",&t, &d);
        if(d == 1) {
            maior = max(maior, 1900 - acc);
            acc += t;
        } else {
            menor = min(menor, 1900 - acc); 
            acc += t;
        }
    }
    if(menor == inf) puts("Infinity");
    else if(maior >= menor) puts("Impossible");
    else printf("%d\n", menor - 1 + acc);
}

