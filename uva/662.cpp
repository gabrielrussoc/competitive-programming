#include <cstdio>
#include <algorithm>
#include <cstring>
#define pii pair<int,int>
#define mp make_pair

using namespace std;

int d[206];
int m[206][46];
int n;
int rest[206];
pii range[206];

int pd(int i, int k){
    if(k == 0){
        int sum = 0;
        for(int j = i+1; j < n; j++)
            sum += abs(d[j]-d[i]);
        return sum;
    }
    if(i == n-1) return 123456;
    int &w = m[i][k];
    if(w != -1) return w;
    
    int ans = 123456;
    for(int j = i+1; j < n; j++) {
        int sum = 0;
        for(int p = i+1; p < j; p++){
               sum += min(abs(d[p]-d[i]),abs(d[j]-d[p]));
        }
        ans = min(ans, sum + pd(j,k-1));
    }
    w = ans;
    return w;
}

void pd2(int i, int k) {
    if(k == 0) return;
    if(i == n-1) return;

    int ans = 123456;
    int ind;
    for(int j = i+1; j < n; j++){
        int sum = 0;
        for(int p = i+1; p < j; p++){
               sum += min(abs(d[p]-d[i]),abs(d[j]-d[p]));
        }
        if(sum + pd(j,k-1) < ans){
            ind = j;
            ans = sum +  pd(j,k-1);
        }
    }
    rest[ind] = 1;
    pd2(ind,k-1);
}

void dist(int i){
    int serv = 123456;
    int ind;
    for(int j = 0; j < n; j++){
        if(rest[j]){
            if(abs(d[j]-d[i]) < serv){
                serv = abs(d[j]-d[i]);
                ind = j; 
            }
        } 
    }
    range[ind].first = min(range[ind].first,i);
    range[ind].second = max(range[ind].second,i);
}

int main(){

    int k,tc = 1;
    while(scanf("%d %d",&n,&k) && n != 0 && k != 0){
        memset(m,-1,sizeof m);
        memset(rest,0,sizeof rest);
        for(int i = 0; i < n; i++){
            range[i].first = 123456;
            range[i].second = -1;
        }
        for(int i = 0; i < n; i++)
            scanf("%d",&d[i]);
        int ans = 123456,ind;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int p = 0; p < i; p++)
                sum += abs(d[i]-d[p]);
            if(pd(i,k-1) + sum < ans) {
                ind = i;
                ans = pd(i,k-1) + sum;
            }
        }
        pd2(ind,k-1);
        rest[ind] = 1;
        for(int i = 0; i < n; i++)
            dist(i);

        printf("Chain %d\n",tc++);
        int j = 1;
        for(int i = 0; i < n; i++){
            if(rest[i]){
                if(range[i].first != range[i].second)
                    printf("Depot %d at restaurant %d serves restaurants %d to %d\n",j++,i+1,range[i].first+1,range[i].second+1);
                else
                    printf("Depot %d at restaurant %d serves restaurant %d\n",j++,i+1,range[i].first+1);
            }
        }
        
        printf("Total distance sum = %d\n\n",ans);
    }       

}
