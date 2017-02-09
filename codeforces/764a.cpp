#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n, m, z;
    int ans = 0;
    scanf("%d %d %d",&n, &m, &z);
    for(int i = 1; i <= z; i++) 
        if(i % m == 0 && i % n == 0) ans++;

    printf("%d\n", ans);
}

