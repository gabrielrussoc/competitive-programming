#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;
int n, v[N], t1[N], t2[N];

bool can(int i, int t) {
    if(t) {
        if(i&1) return v[i] > v[i+1];
        return v[i] < v[i+1];
    } else {
        if(i&1) return v[i] < v[i+1];
        return v[i] > v[i+1];
    }
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",v+i);
    for(int i = n-1; i >= 0; i--) t1[i] = 1 + (can(i,0) ? t1[i+1] : 0); 
    for(int i = n-1; i >= 0; i--) t2[i] = 1 + (can(i,1) ? t2[i+1] : 0); 
    printf("%d\n",max(*max_element(t1,t1+n), *max_element(t2,t2+n)));
}

