#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;


int main() {
    int n, t;
    const int S = 86400;
    scanf("%d %d", &n, &t);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        t -= S-a;
        if(t <= 0) { printf("%d\n", i+1); return 0; }
    }

}

