#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int l, r, x, y, k;
    scanf("%d %d %d %d %d", &l, &r, &x, &y, &k);
    for(int exp = l; exp <= r; exp++) {
        if(exp%k) continue;
        int cst = exp / k;
        if(cst >= x && cst <= y) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}
