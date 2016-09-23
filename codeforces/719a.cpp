#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int n, v[111];

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",v+i);
    if(n == 1) {
        if(v[0] == 0) puts("UP");
        else if(v[0] == 15) puts("DOWN");
        else puts("-1");
        return 0;
    }
    if(v[n-1] > v[n-2]) {
        if(v[n-1] != 15) puts("UP");
        else puts("DOWN");
    } else {
        if(v[n-1] != 0) puts("DOWN");
        else puts("UP");
    }
}

