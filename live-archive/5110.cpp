#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1123456;
int t, n;
int p[N];

int main() {
    for(int i = 2; i * i < N; i++) {
        if(p[i]) continue;
        for(int j = i; j < N; j += i) {
            p[j] = i;
        }
    }
    for(int i = 0; i < N; i++) if(!p[i]) p[i] = i;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        unordered_map<int, int> f;
        int ans = 0;
        while(n > 1) {
            f[p[n]]++;
            ans = max(ans, f[p[n]]);
            n /= p[n];
        }
        printf("%d\n", ans);
    }
}
