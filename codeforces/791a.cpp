#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int a, b;
    scanf("%d %d",&a, &b);
    int ans = 0;
    while(a <= b) {
        ans++;
        a *= 3;
        b *= 2;
    }
    printf("%d\n", ans);
}

