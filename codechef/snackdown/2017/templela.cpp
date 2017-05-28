#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
        
int n;
int h[105];
int s;

int main() {
    scanf("%d",&s);
    while(s--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", h+i);
        bool valid = true;
        for(int i = 1; i <= n/2; i++) if(h[i] != h[i-1] + 1) valid = false;
        for(int i = n/2 + 1; i < n; i++) if(h[i] != h[i-1] - 1) valid = false;
        if(n%2 == 0 || h[0] != 1 || !valid) puts("no");
        else puts("yes");
    }
}

