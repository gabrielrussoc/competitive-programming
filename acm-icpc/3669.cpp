#include <cstdio>
#include <set>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){

    string s;
    char ss[10004];
    int query[1002];
    int acu[10005][27];
    set<int> cuts;    

    int t;
    scanf("%d",&t);
    while(t--){
        memset(acu,0,sizeof acu);
        int k,q, ans = 0;
        scanf("%d",&k);
        for(int i = 0; i < k; i++){
            scanf("%d",&q);
            query[i] = q;
        }
        scanf(" %s",ss);
        s = ss;
        int n = s.length();        
        //printf("n %d\n",n);

        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 26; j++){
                acu[i][j] = acu[i-1][j];
            }
            acu[i][s[i-1]-'a']++;
        }

        cuts.insert(0);
        cuts.insert(n);
        set<int>::iterator l,u;
        for(int i = 0; i < k; i++){
            l = cuts.lower_bound(query[i]);
            --l;
            u = cuts.upper_bound(query[i]);
            //printf("query: %d, l %d u %d \n",query[i],*l,*u);
            for(int j = 0; j < 26; j++){
                int a = acu[query[i]][j] - acu[*l][j];
                int b = acu[*u][j] - acu[query[i]][j];
                if((!a && b) || (!b && a))
                    ans++;
            }
            cuts.insert(query[i]);
        }
        printf("%d\n",ans);
        cuts.clear();
    }


}
