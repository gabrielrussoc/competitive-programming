#include <cstdio>
#include <algorithm>
#define gc getchar_unlocked
using namespace std;

void scanint(int &x){
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
struct node {
    int l,r,i;
};
const int N = 311111, A = 1111111;
int n, q, v[N], rz, vis[A], ans[N], res = 0;
node query[A];

bool comp1 (node a, node b) {
    if(a.l/rz != b.l/rz) return a.l/rz < b.l/rz;
    return a.r < b.r;
}

void add(int x){
    if(!vis[v[x]]) res++;
    vis[v[x]]++;
}

void remove(int x){
    vis[v[x]]--;
    if(!vis[v[x]]) res--;
}

int main(){
    scanint(n);
    rz = 555;
    for(int i = 0; i < n;i++){
        scanint(v[i]);
        vis[v[i]] = 0;
    }
    scanint(q);
    int a, b;
    for (int i = 0; i < q; i++) {
        scanint(a);
        scanint(b);
        query[i].l = a-1, query[i].r = b-1, query[i].i = i;
    } 
    sort(query,query+q,comp1);
    int li, lj;
    li = lj = 0;
    vis[v[0]]++;
    res++;
    for(int k = 0; k < q; k++){
        a = query[k].l;
        b = query[k].r;
        while(li < a) {
            remove(li);
            li++;
        }
        while(li > a) {
            add(li-1);
            li--;
        }
        while(lj > b) {
            remove(lj);
            lj--;
        }
        while(lj < b){
            add(lj+1);
            lj++;
        }

        ans[query[k].i] = res;
    }
    for(int i = 0; i < q; i++) {
        printf("%d\n",ans[i]);
    }
}
