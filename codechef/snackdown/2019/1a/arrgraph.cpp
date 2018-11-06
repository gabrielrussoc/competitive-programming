#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 55;

int uf[N], wf[N];
bool appear[N];

int find(int u) {
    if(u == uf[u]) return u;
    return uf[u] = find(uf[u]);
}

void join(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    if(wf[u] > wf[v]) swap(u, v);
    wf[v] += wf[u];
    uf[u] = v;
}

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

int n, a[N];
vector<int> primes;

bool is_prime(int p) {
    for(int d = 2; d*d <= p; d++)
        if(p % d == 0)
            return false;
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int p = 2; p <= 50; p++)
        if(is_prime(p))
            primes.pb(p);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) { 
            scanf("%d", a+i);
            uf[i] = i;
            wf[i] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(gcd(a[i], a[j]) == 1) join(i, j);
            }
        }
        if(wf[find(0)] == n) {
            puts("0");
            for(int i = 0; i < n; i++) printf("%d ", a[i]);
            puts("");
        } else {
            for(int i = 2; i <= 50; i++) appear[i] = false;
            puts("1");
            for (int p : primes) {
                for(int i = 0; i < n; i++) {
                    if(a[i] % p == 0)
                        appear[p] = true;
                }
            }
            for (int p : primes) {
                if(!appear[p]) {
                    printf("%d ", p);
                    break;
                }
            }
            for(int i = 1; i < n; i++) printf("%d ", a[i]);
            puts("");
        }
    }
}

