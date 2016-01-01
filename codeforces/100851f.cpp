#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1234;

int n, q[N];
ll x[N],y[N], w;
ll e[N], d[N];

ll qd(ll a){
    return a*a;
}

ll dis (int u, int v){
    if(!u) return qd(x[v]);
    if(!v) return qd(x[u]);
    if(u == n+1) return qd(w-x[v]);
    if(v == n+1) return qd(w-x[u]);
    return qd(x[u]-x[v]) + qd(y[u]-y[v]);
}

void esq(){
    for(int i = 0; i < n+2; i++) 
        e[i] = LLONG_MAX, q[i] = 1;
    e[0] = 0;
    while(1){
        int at;
        ll mini = LLONG_MAX;
        int ok = 0;
        for(int i = 0; i < n+2; i++)
            if(q[i] && e[i] < mini) {
                at = i;
                mini = e[i];
                ok = 1;
            }
        if(!ok) break;
        q[at] = 0;
        for(int i = 0; i < n+2; i++)
            if(i != at && e[i] > max(e[at],dis(i,at)))
                e[i] = max(e[at],dis(i,at));
    }
}

void dir(){
    for(int i = 0; i < n+2; i++) 
        d[i] = LLONG_MAX, q[i] = 1;
    d[n+1] = 0;
    while(1){
        int at;
        ll mini = LLONG_MAX;
        int ok = 0;
        for(int i = 0; i < n+2; i++)
            if(q[i] && d[i] < mini){
                at = i;
                mini = d[i];
                ok = 1;
            }
        if(!ok) break;
        q[at] = 0;
        for(int i = 0; i < n+2; i++)
            if(i != at && d[i] > max(d[at],dis(i,at)))
                d[i] = max(d[at],dis(i,at));
    }
}
int main(){
    freopen("froggy.in","r",stdin);
    freopen("froggy.out","w",stdout);
    cin >> w >> n;
    for(int i = 1; i <= n; i++) 
        cin >> x[i] >> y[i];
    x[n+1] = w;
    x[0] = 0;
    esq();
    dir();
    int p,q;
    double mini = LLONG_MAX;
    for(int i = 0; i < n+2; i++)
        for(int j = i+1; j < n+2; j++){
            double a,b;
            a = max(e[i],d[j]);
            b = max(e[j],d[i]);
            double tmp = min(a,b);
            if(mini > max(tmp, (double) dis(i,j)/4)){
                mini = max(tmp,(double) dis(i,j)/4);
                p = i;
                q = j;
            }
        }
    double xa,ya;
    xa = (double) (x[p] + x[q])/2;
    ya = (double) (y[p] + y[q])/2;
    if(!p) ya = y[q];
    if(q == n+1) ya = y[p];
    printf("%.3f %.3f\n",xa,ya);
}
