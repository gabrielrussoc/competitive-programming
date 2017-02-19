#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1123456;

int n, m, k;
int f[N], s[N], p[N];

bool can(int q) {
    int i = 0;
    int j = m - q;
    int d = 0;
    int l = 0;
    while(i < n && j < m) {
        if(min(f[i], s[j]) < d) return false;
        if(f[i] < s[j]) i++;
        else j++;
        l++;
        if(l%k == 0) d++;
    }
    while(i < n) {
        if(f[i] < d) return false;
        i++;
        l++;
        if(l%k == 0) d++;
    }
    while(j < m) {
        if(s[j] < d) return false;
        j++;
        l++;
        if(l%k == 0) d++;
    }
    return true;
}

bool comp(int i, int j) {
    return s[i] < s[j];
}

int main() {
    scanf("%d %d %d",&n, &m, &k);
    for(int i = 0; i < n; i++) scanf("%d", f+i);
    for(int i = 0; i < m; i++) {
        scanf("%d", s+i);
        p[i] = i;
    }
    sort(f, f+n);
    sort(p, p+m, comp);
    sort(s, s+m);

    int lo = 0, hi = m;
    while(lo < hi) {
        int mid = (lo + hi+1)/2;
        if(can(mid)) lo = mid;
        else hi = mid-1;
    }
    if(can(lo)) { 
        printf("%d\n", lo);
        for(int i = m-1; i >= m - lo; i--) printf("%d ", p[i] + 1);
        putchar('\n');
    }
    else puts("-1");
}

