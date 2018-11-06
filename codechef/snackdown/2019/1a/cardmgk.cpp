#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;

int n;
int a[N];

bool sorted(int l, int r) {
    for(int i = l+1; i < r; i++) {
        if(a[i] < a[i-1]) return false;
    }
    return true;
}

int maxi(int l, int r) {
    int ret = a[l];
    for(int i = l; i < r; i++) ret = max(ret, a[i]);
    return ret;
}

int mini(int l, int r) {
    int ret = a[l];
    for(int i = l; i < r; i++) ret = min(ret, a[i]);
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", a+i);
        int k = 1;
        while(k < n && a[k] >= a[k-1]) k++;
        if(k == n || (sorted(0, k) && sorted(k, n) && mini(0, k) >= maxi(k, n)))
            puts("YES");
        else puts("NO");
    }
}

