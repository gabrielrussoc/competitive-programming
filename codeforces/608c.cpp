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
const int N = 100009;
const int A = 1000009;
const int modn = 1000000007;

struct bcn {
    int pos, pwr;
} v[N];

int acc[A+7];
int res[N];

bool comp (bcn a, bcn b){
    return a.pos < b.pos;
}

int explo(int i){
    int x = max(v[i].pos-v[i].pwr-1, 0);
    return acc[v[i].pos-1] - acc[x];
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d",&v[i].pos,&v[i].pwr);
        v[i].pos++;
        acc[v[i].pos]++;
    }
    sort(v,v+n,comp);
    acc[0] = 0;
    for(int i = 0; i < A; i++) 
        acc[i+1] += acc[i];
    for(int i = 0; i < n; i++){
        res[i] = explo(i);
        int lo = 0, hi = i;
        while(lo != hi){
            int mid = (lo+hi+1)/2;
            if(v[mid].pos < v[i].pos-v[i].pwr) lo = mid;
            else hi = mid-1;
        }
        if(v[lo].pos < v[i].pos - v[i].pwr) res[i] += res[lo];
    }
    int mini = INT_MAX;
    for(int i = 0; i < n; i++) mini = min(mini,n-i-1+res[i]);
    printf("%d\n",mini);
    return 0;
}
