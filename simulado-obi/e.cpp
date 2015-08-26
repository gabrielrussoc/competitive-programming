#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#define pii pair<int,int>
#define ff first
#define ss second

using namespace std;

pii v[1000006];
int n;

bool find(pii k){
    int q1,q2,q3,q4;
    q1 = q2 = q3 = q4 = 0;
    for(int i = 0; i < n; i++){
        if(v[i].ff > k.ff){
            if(v[i].ss < k.ss)
                q1++;
            if(v[i].ss > k.ss)
                q2++; 
        }
        else if(v[i].ff < k.ff){
            if(v[i].ss < k.ss)
                q3++;
            if(v[i].ss > k.ss)
                q4++; 
        }
        if(q1 && q2 && q3 && q4) return true;
    }
    return false;

}

int main(){
    int d;
    scanf("%d %d",&n,&d);
    for(int i = 0; i < n; i++){
        scanf("%d %d",&v[i].ff,&v[i].ss);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(find(v[i])) ans++;
    }
    printf("%d\n",ans);

}
