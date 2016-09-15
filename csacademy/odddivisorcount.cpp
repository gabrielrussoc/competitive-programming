#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

int div(int x) {
    int ret = 0;
    for(int i = 1; i <= x; i++)
        if(x%i == 0) ret++;
    return ret;
}

int main() {
    int a, b;
    scanf("%d %d",&a,&b);
    int ans = 0;
    for(int i = a; i <= b; i++) {
        if(div(i)&1) ans++;
    }
    printf("%d\n",ans);
}

