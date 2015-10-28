#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//////////////0123456789
const int N = 200005;
int n, t, v[N], rz;
ll freq[1000006];
struct query{
    int l, r, i;
    ll res;
} q[N];

ll ans;

bool comp (query a, query b){
    if(a.l/rz != b.l/rz) return a.l/rz < b.l/rz;
    return a.r < b.r;
}

bool comp2(query a, query b){
    return a.i < b.i;
}

inline void add(ll x){
    ans -= freq[x]*freq[x]*x;
    freq[x]++;
    ans += freq[x]*freq[x]*x;
}

inline void del(ll x){
    ans -= freq[x]*freq[x]*x;
    freq[x]--;
    ans += freq[x]*freq[x]*x;
}

int main(){
    for(int i = 0; i < 1000001; i++) freq[i] = 0;
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    rz = sqrt(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < t; i++){
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }
    sort(q,q+t,comp);
    int cl, cr;
    ans = 0;
    int a,b;
    cl = cr = 0;
    add(v[0]);
    for(int i = 0; i < t; i++){
        a = q[i].l - 1;
        b = q[i].r - 1;
        while(cl < a){
            del(v[cl]);
            cl++;
        }
        while(cl > a){
            cl--;
            add(v[cl]);
        }
        while(cr < b){
            cr++;
            add(v[cr]);
        }
        while(cr > b){
            del(v[cr]);
            cr--;
        }
        q[i].res = ans;
    }
    sort(q,q+t,comp2);
    for(int i = 0; i < t; i++)
        cout << q[i].res << '\n';
}
