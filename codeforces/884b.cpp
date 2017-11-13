#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        sum += ll(a);
    }
    if(sum == ll(x-n+1)) puts("YES");
    else puts("NO");
}

