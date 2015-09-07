#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    
    set<int> s;
    int ans = 0,n;
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        char c;
        int a;
        scanf(" %c %d",&c,&a);
        if (c == '+') s.insert(a);
        else{
            if(s.find(a) == s.end()) ans++;
            s.erase(a);
        }
        int sz = s.size();
        ans = max(ans,sz);
    }
    printf("%d\n",ans);
    
}
