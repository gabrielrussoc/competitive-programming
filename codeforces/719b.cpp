#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 112345;
int n;
char v[N];

char other (char c) {
    if(c == 'r') return 'b';
    return 'r';
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf(" %c",v+i);
    }
    char c = 'r';
    int r = 0, b = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] != c) {
            if(c == 'r') r++;
            else b++;
        }
        c = other(c);    
    }
    int ans = min(r,b) + abs(r-b);
    r = b = 0;
    c = 'b';
    for(int i = 0; i < n; i++) {
        if(v[i] != c) {
            if(c == 'r') r++;
            else b++;
        }
        c = other(c);
    }
    ans = min(ans, min(r,b) + abs(r-b));
    printf("%d\n",ans);
}

