#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1234;
char s[N];
int ans[N], ps, n;

int main() {
    scanf("%d",&n);
    scanf(" %s",s);
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'W') {
            if(i-j > 0) ans[ps++] = i-j;
            j = i+1;
        }
    }
    if(n-j > 0) ans[ps++] = n-j;
    printf("%d\n", ps);
    for(int i = 0; i < ps; i++) printf("%d%c",ans[i]," \n"[i==ps-1]);
}

