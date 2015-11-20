#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define ff first
#define ss second
using namespace std;
typedef long long ll;

//////////////0123456789
const int N = 100005;
const int modn = 1000000007;


pii h[N];
map<int,int> m;
int bit[N];

bool comp (pii a, pii b){
    return a.ss < b.ss;
}

int query(int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

void update(int idx, int val){
    for(int i = idx; i < N; i += i&-i)
        bit[i] += val;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&h[i].ff);
        h[i].ss = i;
    }
    sort(h,h+n);
    int k = 1;
    for(int i = 0; i < n; i++){
        if(m.find(h[i].ff) == m.end()) m[h[i].ff] = k++;
        h[i].ff = m[h[i].ff];
        update(h[i].ff,1);
    }
    sort(h,h+n,comp);
    int ans = 0;
    int gmax = h[0].ff;
    for(int i = 0; i < n; i++){
        update(h[i].ff,-1);
        if(!query(gmax-1)){
            ans++;
            gmax = h[i+1].ff;
        }
        else gmax = max(gmax,h[i].ff);
    }
    printf("%d\n",ans);
}
