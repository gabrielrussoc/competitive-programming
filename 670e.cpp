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
const int N = 500005;
const int modn = 1000000007;

char v[N];
int par[N];
int dir[N], esq[N];
int p, n, m;

int main() {
    scanf("%d %d %d",&n,&m,&p);
    p--;
    stack<int> s;
    for(int i = 0; i < n; i++) {
        esq[i] = i-1;
        dir[i] = i+1;
        scanf(" %c",v+i);
        if(v[i] == ')') {
            int j = s.top();
            s.pop();
            par[i] = j;
            par[j] = i;
        } else s.push(i);
    }
    dir[n-1] = -1;
    for(int i = 0; i < m; i++) {
        char op;
        scanf(" %c",&op);
        if(op == 'R') p = dir[p];
        else if(op == 'L') p = esq[p];
        else {
            int a = p;
            int b = par[p];
            if(a > b) swap(a,b);
            if(esq[a] != -1) dir[esq[a]] = dir[b];
            if(dir[b] != -1) esq[dir[b]] = esq[a];
            a = esq[a]; b = dir[b];
            if(b != -1) p = b;
            else p = a;
        }
    }
    while(esq[p] != -1) p = esq[p];
    while(p != -1) {
        putchar(v[p]);
        p = dir[p];
    }
    putchar('\n');
    
}

