#include <cstdio>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

using namespace std;

const int MAX = 1 << 16;

int main(){
    int t, n,k;

    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        queue<pii> q;
        vector<int> adj[MAX];
        int m[MAX];
        int a;
        for(int i = 0; i < 1 << n; i++){
            scanf("%d",&a);
            q.push(mp(a,i));
            m[i] = a;
        }
        while(q.size() > 1){
            pii x, y; 
            x = q.front();
            q.pop();
            y = q.front();
            q.pop();
            adj[x.ss].pb(y.ss);
            adj[y.ss].pb(x.ss);
            if(x.ff == y.ff){
                if(x.ss < y.ss)
                    q.push(mp(min(k,m[x.ss]),x.ss));
                else
                    q.push(mp(min(k,m[x.ss]),y.ss));
            }
            else {
                if(x.ff > y.ff){
                    q.push(mp(min(m[x.ss],x.ff-y.ff+k),x.ss));
                }
                else
                    q.push(mp(min(m[y.ss],y.ff-x.ff+k),y.ss));
            }
        }
        pii w = q.front();
        q.pop();
        int p = adj[w.ss].size();
        printf("%d\n",w.ss + 1);
        for(int i = 0; i < p; i++)
            printf("%d%c",adj[w.ss][i] + 1, i == p-1 ? '\n' : ' ');
    }

}
