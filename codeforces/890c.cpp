#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 200005;
int n, f[N];

int main() {
    scanf("%d", &n);
    int ans = 1;
    f[0] = true;
    for(int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if(f[t]) f[t] = false;
        else ans++;
        f[i+1] = true;
    }
    printf("%d\n", ans);
}

