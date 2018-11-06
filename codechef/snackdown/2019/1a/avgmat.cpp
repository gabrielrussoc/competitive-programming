#include <bits/stdc++.h>
#define pb push_back
#define left esquerda
#define right direita
using namespace std;
typedef long long ll;

const int off = 601;
const int N = 2005;
char s[N];
int n, m;
ll g[N][N], acc[N][N], left[N][N], right[N][N];

void clear() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            acc[i][j] = left[i][j] = right[i][j] = g[i][j] = 0;
}

void build() {
    for(int i = 1; i < N; i++)
        for(int j = 1; j < N; j++)
            left[i][j] = g[i][j] + left[i-1][j-1];

    for(int i = 1; i < N; i++)
        for(int j = N-2; j >= 0; j--)
            right[i][j] = right[i-1][j+1] + g[i][j];

    for(int j = 2; j < N; j++) {
        for(int i = 1; i < N-1; i++) {
            acc[i][j] = acc[i-1][j-1] + acc[i+1][j-1] - acc[i][j-2] + g[i][j] + g[i][j-1];
        }
    }
    /* for(int i = off; i < off+n; i++) { */
    /*     for(int j = off; j < off+m; j++) */
    /*         printf("%lld ", acc[i][j]); */
    /*     puts(""); */
    /* } */
}

ll calc(int d) {
    ll ret = 0;
    /* printf("==== %d\n", d); */
    for(int i = off; i < off+n; i++) {
        for(int j = off; j < off+m; j++) {
            if(!g[i][j]) continue;
            ll up = left[i+d][j] - left[i-1][j-d-1];
            ll down = right[i][j-d] - right[i-d-1][j+1];
            ll loc = acc[i][j+d] - acc[i-d][j] - acc[i+d][j] + acc[i][j-d] + up + down - g[i][j-d] - 1; 
            /* printf("(%d, %d) = %lld\n", i-off, j-off, loc); */
            ret += loc;
        }
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        clear();
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf(" %s", s);
            for(int j = 0; j < m; j++)
                g[i+off][j+off] = s[j] - '0';
        }
        build();
        ll all = 0;
        for(int d = 1; d <= n+m-2; d++) {
            ll ans = calc(d) / 2 - all;
            printf("%lld ", ans);
            all += ans;
        }
        puts("");
    }
}

