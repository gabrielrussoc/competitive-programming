#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 200005;
char s[N];
int p[N], z[N];

int main() {
    int n;
    scanf("%d",&n);
    s[0] = 'a';
    for(int i = 0; i < n; i++) {
        scanf("%d",p+i);
        if(!i) continue;
        if(p[i] == 0) s[i] = s[p[i-1]] + 1;
        else s[i] = s[p[i]-1];
    }
    z[0] = 0;
    int l, r; l = r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r) z[i] = min(z[i-l], r-i+1);
        while(z[i] + i < n && s[z[i] + i] == s[z[i]]) z[i]++;
        if(r < i + z[i] - 1) l = i, r = i + z[i] - 1;
    }
    for(int i = 0; i < n; i++) printf("%d%c", z[i], " \n"[i==n-1]);
    
}

