#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;
int n, k, s[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++) scanf("%d", s+i);
        sort(s, s+n, greater<int>());
        k--;
        int j = k;
        while(j < n && s[j] == s[k]) j++;
        printf("%d\n", j);
    }
}

