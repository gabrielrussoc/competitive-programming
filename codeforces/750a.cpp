#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    scanf("%d %d",&n,&k);
    int ans = 0, cont = 0;
    while(ans + 5*(cont+1) <= 4*60-k && cont < n) {
        ans += 5*(cont+1);
        cont++;
    }
    printf("%d\n",cont);
}

