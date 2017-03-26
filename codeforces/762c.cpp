#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;
const int inf = 1234567;
char a[N], b[N];
int n, m, p[N], s[N];

int main() {
    scanf("%s %s", a, b);
    n = strlen(a);
    m = strlen(b);
    for(int i = 1; i <= m; i++) s[i] = p[i] = inf;
    int j = 0;
    for(int i = 0; i < m; i++) {
        while(j != n && b[i] != a[j]) j++;
        if(j != n) p[i+1] = j+1;
        else break;
        j++;
    }
    j = n-1;
    for(int i = m-1; i >= 0; i--) {
        while(j != -1 && b[i] != a[j]) j--;
        if(j != -1) s[m-i] = n-j;
        else break;
        j--;
    }
    int ai, aj, ans = 0;
    j = m;
    for(int i = 0; i <= m; i++) {
        if(i + j > m) j = m-i;
        while(j != -1 && p[i] + s[j] > n) j--;
        if(j != -1 && i + j  > ans) {
            ans = i + j;
            ai = i;
            aj = m-j;
        }
    }
    if(ans == 0) puts("-");
    else {
        for(int i = 0; i < ai; i++) putchar(b[i]);
        for(int i = aj; i < m; i++) putchar(b[i]);
        putchar('\n');
    }

}

