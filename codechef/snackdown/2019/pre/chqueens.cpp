#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 250;

int t, n, m, x, y;

bool spec[N][N];
bool paint;

void push(int r, int c) {
    if(paint) spec[r][c] = true;
}

ll mark(int r, int c) {
    int i, j;

    ll qt = 0;

    i = r;
    j = c;
    while(i <= n && j <= m && (i != x || j != y || paint)) {
        push(i, j);
        i += 1;
        j += 1;
        qt++;
    }

    i = r;
    j = c;
    while(i > 0 && j > 0 && (i != x || j != y || paint)) {
        push(i, j);
        i -= 1;
        j -= 1;
        qt++;
    }

    i = r;
    j = c;
    while(i > 0 && j <= m && (i != x || j != y || paint)) {
        push(i, j);
        i -= 1;
        j += 1;
        qt++;
    }
    
    i = r;
    j = c;
    while(i <= n && j > 0 && (i != x || j != y || paint)) {
        push(i, j);
        i += 1;
        j -= 1;
        qt++;
    }
    
    i = r;
    j = c;
    while(i <= n && (i != x || j != y || paint)) {
        push(i, j);
        i += 1;
        qt++;
    }
    
    i = r;
    j = c;
    while(i > 0 && (i != x || j != y || paint)) {
        push(i, j);
        i -= 1;
        qt++;
    }
    
    i = r;
    j = c;
    while(j <= m && (i != x || j != y || paint)) {
        push(i, j);
        j += 1;
        qt++;
    }
    
    i = r;
    j = c;
    while(j > 0 && (i != x || j != y || paint)) {
        push(i, j);
        j -= 1;
        qt++;
    }

    return qt - 7;
}

ll reach(int r, int c) {
    ll row = n - 1;
    ll col = m - 1;
    ll diag = min(r-1,c-1) + min(n-r, m-c);
    ll rev = min(r-1, m-c) + min(c-1, n-r);
    return row + col + diag + rev + 1;
}

ll calc(int r, int c) {
    if(r == x && c == y) return 0;
    if (spec[r][c])
        return ll(n*m) - 1ll - mark(r, c);
    else
        return ll(n*m) - 1ll - reach(r, c);
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d %d", &n, &m, &x, &y);
    
        for(int r = 1; r <= n; r++)
            for(int c = 1; c <= m; c++)
                spec[r][c] = false;

        ll ans = 0;

        paint = true;
        mark(x, y);
        paint = false;

        for(int r = 1; r <= n; r++) {
            for(int c = 1; c <= m; c++) {
                /* printf("(%d, %d) = %lld\n", r, c, loc); */
                ans += calc(r, c);
            }
        }
        printf("%lld\n", ans);
    }
}

