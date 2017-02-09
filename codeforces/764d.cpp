#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    puts("YES");
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%d\n", 2 * (x2&1) + (y2&1) + 1);
    }
}

