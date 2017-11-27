#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 366;
int a[N], n;

int main() {
    scanf("%d", &n);
    int tot = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", a+i);
        tot += a[i];
    }

    int ans = tot;
    for(int i = 0; i < n; i++) {
        int loc = 0;
        for(int j = i; j < n; j++) {
            loc += a[j];
            ans = min(ans, abs(tot-loc-loc));
        }
    }
    printf("%d\n", ans);

}

