#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 105;
int n, k;

int main() {
    scanf("%d %d",&n, &k);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        sum += a;
    }
    int ans = 0;

    while(round(double(sum) / double(n)) < k) {
        sum += k;
        n++;
        ans++;
    }
    printf("%d\n", ans);

}

