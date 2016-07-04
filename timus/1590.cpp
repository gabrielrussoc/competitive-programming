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
const int N = 5007;
const int modn = 1000000007;

char s[N];

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
} tr[2*N];
int ts = 0;

int new_node(int l, int r, int p) {
    tr[ts] = node(l,r,p);
    return ts++;
}


void build() {
    int n = strlen(s);
    //s[n++] = '$';
    int cn, cd;
    new_node(0,-1, 0); //raiz
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
                    tr[cn].f[s[j]] = new_node(j, n-1, cn);
                    break;
                } else { //to no meio da aresta, tem que quebrar
                    int mid = new_node(tr[cn].l, tr[cn].l + cd - 1, tr[cn].p);
                    tr[mid].f[s[j]] = new_node(j, n-1, mid); 
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

int count(int u, int p) {
    int ans = 0;
    for(auto v : tr[u].f)
        if(v.ss != p) ans += tr[v.ss].len() + count(v.ss,u);
    return ans;
}

int main() {
    scanf(" %s",s);
    build();
    printf("%d\n",count(0,0));
}

