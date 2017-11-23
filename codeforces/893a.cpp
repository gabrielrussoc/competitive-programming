#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 105;
int a[N], n;

int ot(int x, int y) {
    if(x > y) swap(x,y);
    if(x == 1 && y == 2) return 3;
    if(x == 1 && y == 3) return 2;
    return 1;
}

bool can(int x, int y) {
    for(int i = 0; i < n; i++) {
        if(a[i] != x && a[i] != y) return false;
        if(a[i] == x) y = ot(x,y);
        else x = ot(x,y);
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a+i);
    if(can(1,2)) puts("YES");
    else puts("NO");
}

