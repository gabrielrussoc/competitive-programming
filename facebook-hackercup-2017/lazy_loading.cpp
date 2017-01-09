#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int solve(){
    int n;
    multiset<int> w;
    multiset<int>::iterator it;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d",&x);
        w.insert(x);
    }
    int ans = 0;
    while(!w.empty()) {
        it = w.end(); it--;
        int sum = *it;
        w.erase(it);
        int cont = 1;
        while(sum*cont < 50 && !w.empty()) {
            cont++;
            w.erase(w.begin());
        }
        if(sum*cont < 50) break;
        ans++;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d",&t);
    for(int tc = 1; tc <= t; tc++) {
        printf("Case #%d: %d\n", tc, solve());
    }
}

