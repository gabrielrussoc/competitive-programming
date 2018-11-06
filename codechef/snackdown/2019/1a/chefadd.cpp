#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int qa = __builtin_popcount(a);
        int qb = __builtin_popcount(b);

        int ans = 0;
        for(int na = 0; na < N; na++) {
            if(__builtin_popcount(na) != qa) continue;
            int nb = c - na;
            if(c >= 0 && __builtin_popcount(nb) == qb) ans++; 
        }
        printf("%d\n", ans);
    }


}

