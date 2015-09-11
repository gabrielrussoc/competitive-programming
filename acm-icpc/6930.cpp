#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
#include <queue>
#define ff first
#define ss second

using namespace std;

pii w[1003], v[1003];
int r[1003],s[1003];

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b,a%b);
}

int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d %d %d",&w[i].ff,&w[i].ss,&r[i]);
            v[i].ff = v[i].ss = 0;
        }
        v[0].ff = v[0].ss = 1;
        s[0] = 1;
        queue<int> q;
        q.push(0);
        while(q.size()){
            int x = q.front();
            q.pop();
            for(int i = 0; i < n; i++){
                if(i != x && v[i].ss == 0){
                    int dr = (r[i]+r[x])*(r[i]+r[x]);
                    int d = (w[i].ff - w[x].ff)*(w[i].ff -w[x].ff) + (w[i].ss - w[x].ss)*(w[i].ss - w[x].ss);
                    if(d == dr){ 
                        s[i] = -s[x];
                        int a = v[x].ff * r[x];
                        int b = v[x].ss * r[i];
                        int c = mdc(a,b);
                        v[i].ff = a/c;
                        v[i].ss = b/c;
                        q.push(i);   
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(v[i].ss == 0)
                printf("not moving\n");
            else {
                if(v[i].ss == 1)
                    printf("%d ",v[i].ff);
                else 
                    printf("%d/%d ",v[i].ff,v[i].ss);
                if(s[i] == 1) printf("clockwise\n");
                else printf("counterclockwise\n");
            }
        }
    }

}
