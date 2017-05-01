#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 5003;
int L, S, M, D, B;
int s[N], m[N], d[N], b[N];
int esq[N*N], dir[N*N];

int main() {
    while(scanf("%d %d %d %d %d",&L, &S, &M, &D, &B) && L != 0) {
        for(int i = 0; i < S; i++) scanf("%d", s+i);
        for(int i = 0; i < M; i++) scanf("%d", m+i);
        for(int i = 0; i < D; i++) scanf("%d", d+i);
        for(int i = 0; i < B; i++) scanf("%d", b+i);

        int p, q;
        p = q = 0;
        for(int i = 0; i < S; i++)
            for(int j = 0; j < M; j++)
                esq[p++] = s[i] + m[j];
        for(int i = 0; i < D; i++)
            for(int j = 0; j < B; j++)
                dir[q++] = d[i] + b[j];

        sort(esq, esq+p);
        sort(dir, dir+q);

        ll ans = 0;
        for(int i = 0; i < p; i++) {
            int j = upper_bound(dir, dir+q, L-esq[i]) - dir;
            ans += ll(j);
        }
        printf("%lld\n", ans);
    }
}
