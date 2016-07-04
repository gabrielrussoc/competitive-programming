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

char s[N], t[N], sz[2*N];
int k, ts;

struct node {
    int l, r, p;
    map<char, int> f;
    node () {}
    node (int ll, int rr, int pp) {
        l = ll;
        r = rr;
        p = pp;
    }
    inline int len() { return r-l+1; }
    inline char operator[](int i) { return s[i+l]; }
} tra[2*N], trb[2*N];

int new_node(node *tr, int l, int r, int p) {
    tr[ts] = node(l,r,p);
    return ts++;
}

void build(node *tr) {
    ts = 0;
    int n = strlen(s);
    s[n++] = '$';
    int cn, cd;
    new_node(tr, 0,-1, 0); //raiz
    for (int i = 0; i < n; i++) {
        cn = cd = 0;
        for(int j = i; j < n; j++) {
            if(cd == tr[cn].len() ? tr[cn].f.count(s[j]) : tr[cn][cd] == s[j]) { //char ta na trie
                if(cd == tr[cn].len()) {
                    cn = tr[cn].f[s[j]];
                    cd = 0;
                }
                cd++;
            } else { //char nao ta na trie
                if(cd == tr[cn].len() && !tr[cn].f.count(s[j])) { //to num vertice, só adiciono a folha
                    tr[cn].f[s[j]] = new_node(tr, j, n-1, cn);
                    break;
                } else { //to no meio da aresta, tem que quebrar
                    int mid = new_node(tr, tr[cn].l, tr[cn].l + cd - 1, tr[cn].p);
                    tr[mid].f[s[j]] = new_node(tr, j, n-1, mid); 
                    tr[mid].f[tr[cn][cd]] = cn;
                    tr[cn].l += cd;
                    tr[cn].p = mid;
                    tr[tr[mid].p].f[tr[mid][0]] = mid;
                    break;
                }
            }   
        }
    }
}

void printa(int l, int r) {
    for(int i = l; i <= r; i++) putchar(s[i]);
    putchar('\n');
}

int get(int l, int r) {
    int cn, cd;
    cn = cd = 0;
    for(int j = l; j <= r; j++) {
        if(cd == trb[cn].len() ? trb[cn].f.count(s[j]) : trb[cn][cd] == s[j]) { //char ta na trie
            if(cd == trb[cn].len()) {
                cn = trb[cn].f[s[j]];
                cd = 0;
            }
            cd++;
        }
        else return -1;
    }
    return sz[cn];
}

int dfs(int u, int p) {
    if(!trb[u].f.size()) return sz[u] = 1;
    for(map<char,int>::iterator v = trb[u].f.begin(); v != trb[u].f.end(); v++)
        if(v->ss != p) sz[u] += dfs(v->ss, u);
    return sz[u];
}

int solve(){
    int ans = 0;
    dfs(0, 0);
    for(int u = 1; u < ts; u++) {
        for(int x = 0; x < tra[u].len(); x++) {
            if(get(tra[u].l, tra[u].l+x) == k) ans++;
        }
    }
    return ans;
}

int main() {
    //freopen("strings.in", "r", stdin);
    //freopen("strings.out", "w", stdout);
    scanf(" %s %s %d", s,t,&k);
    swap(s,t); build(trb);
    swap(s,t); build(tra);
    printf("%d\n", solve());
}

