#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double cood;

const cood eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 50004;
const int modn = 1000000007;
typedef complex<ll> point;

int ss, n;
const int A = 20011;
const int B = 20021;
int xg;
int p[2*N];

struct seg {
    point p;
    int i;
    bool f; 
    seg () {}
    seg (point a, int j, bool c): p(a), i(j), f(c){}
} v[2*N];
const cood PI = acos(-1);
ll x (point a) { return a.real(); }
ll y (point a) { return a.imag(); }
ll cross (point a, point b){ return y(conj(a)*b); }

cood cur_y(int i){
    return y(v[i<<1].p) + cood(y(v[i<<1|1].p)-y(v[i<<1].p)) / cood(x(v[i<<1|1].p)-x(v[i<<1].p)) * cood(xg-x(v[i<<1].p)); 
}

bool comp(int i, int j) {
    return x(v[i].p) < x(v[j].p);
}

struct comp2 {
    bool operator () (const int &a, const int &b) const {
        cood p,q;
        p = cur_y(a), q = cur_y(b);
        return p < q-eps;
    }
};

bool int_ex (ll a, ll b, ll c, ll d) {
    if(a > b) swap(a,b);
    if(c > d) swap(c,d);
    return max(a,c) <= min(b,d);
}

int sig(ll x){
    return (x>0)-(x<0); 
}

bool intersect (point a, point b, point c, point d){
    return (sig(cross(d-c,a-c))*sig(cross(d-c,b-c)) <= 0) 
        && (sig(cross(b-a,c-a))*sig(cross(b-a,d-a)) <= 0) 
        && int_ex(x(a),x(b),x(c),x(d)) 
        && int_ex(y(a),y(b),y(c),y(d));
}

bool inter(int a, int b){
    return intersect(v[a<<1].p,v[a<<1|1].p,v[b<<1].p,v[b<<1|1].p);
}

int main() {
    set<int,comp2> s;
    set<int,comp2>::iterator it, it2;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int a,b,c,d;
        point p1, p2;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        p1 = point(A*a + B*b, A*a - B*b);
        p2 = point(A*c + B*d, A*c - B*d);
        if(x(p1) > x(p2)) swap(p1,p2);
        v[ss++] = seg(p1,i,1);
        v[ss++] = seg(p2,i,0);
    }
    for(int i = 0; i < ss; i++) p[i] = i;
    sort(p,p+ss,comp);
    for(int i = 0; i < ss; i++){
        xg = x(v[p[i]].p);
        int a,b, at = v[p[i]].i;
        if(v[p[i]].f){
            it = s.lower_bound(at);
            if(it != s.end()){
                a = at; b = *it;
                if(inter(a,b)){
                    printf("YES\n%d %d\n",a+1,b+1);
                    return 0;
                }
            }
            if(it != s.begin()){
                it--;
                a = *it; b = at;
                if(inter(a,b)){
                    printf("YES\n%d %d\n",a+1,b+1);
                    return 0;
                }
            }
            s.insert(at);
        }
        else {
            s.erase(at);
            it = s.lower_bound(at);
            it2 = it;
            if(it != s.end() && it != s.begin()){ 
                it--;
                a = *it, b = *it2;
                if(inter(a,b)){
                    printf("YES\n%d %d\n",a+1,b+1);
                    return 0;
                }
            }
        }
    }
    puts("NO");
}

