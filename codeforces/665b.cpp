#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 10004;
const int modn = 1000000007;

int v[105], prox[105], ant[105], head;

void f (int i) {
    if(ant[i] == -1) return;
    prox[ant[i]] = prox[i];
    if(prox[i] != -1)
        ant[prox[i]] = ant[i];
    prox[i] = head;
    ant[i] = -1;
    ant[head] = i;
    head = i;
}

int main() {
    int n, k, m;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0; i < k; i++) {
        prox[i] = i != k-1 ? i+1 : -1;
        ant[i] = i-1;
        scanf("%d",v+i);
    }
    int ans = 0;
    while(n--) {
        int x;
        for(int i = 0; i < m; i++) {
            scanf("%d",&x);
            int cont = 0;
            int j = head;
            while(v[j] != x) {
                cont++;
                j = prox[j];
            }
            f(j);
            ans += cont+1;
        }
    }
    printf("%d\n",ans);
}

