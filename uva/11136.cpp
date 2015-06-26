#include <bits/stdc++.h>

using namespace std;

int main(){

    multiset<int> s;
    int n;
    while(scanf("%d",&n) && n != 0){

        long long ans = 0;
        set<int>::iterator l,h;
        for(int i = 0; i < n; i++){
            int k;
            scanf("%d",&k);
            for(int j = 0; j < k; j++){
                int a;
                scanf("%d",&a);
                s.insert(a);    
            }
            l = s.begin();
            h = --s.end();
            ans += (*h) - (*l);
            s.erase(l);
            s.erase(h);
        }
        printf("%lld\n",ans);
        s.clear();
    }

}
