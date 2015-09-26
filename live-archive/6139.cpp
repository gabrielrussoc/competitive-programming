#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
const int N = 100005;
using namespace std;
int bit[N][2];
int in[N];
int n,k;
typedef pair<int,int> pii;

void update(int idx, int x){
    for(int i = idx; i <= n; i += i&-i){
        if(x < 0) bit[i][0]++;
        else bit[i][1]++; 
    }
}
void remove(int idx, int x){
    for(int i = idx; i <= n; i += i&-i){
        if(x < 0) bit[i][0]--;
        else bit[i][1]--; 
    }
}

pii query(int idx){
    pii sum = mp(0,0);
    for(int i = idx; i > 0; i -= i&-i){
        sum.ff += bit[i][0];
        sum.ss += bit[i][1];
    }
    return sum;
}

int main(){
    while(scanf("%d %d",&n,&k) != EOF){
    memset(bit,0,sizeof bit);
    int foo;
    for(int i = 0; i < n; i++){
        scanf("%d",&foo);
        in[i+1] = foo;
        if(foo <= 0)
            update(i+1,foo);
    }
    for(int i = 0; i < k; i++){
        char c;
        int a,b;
        scanf(" %c %d %d",&c,&a,&b);
        
        if(c == 'C'){
            if(!in[a] && b){
                remove(a,0);
                if(b < 0) update(a,b);
            } 
            else if(in[a] < 0 && !b){
                remove(a,-1);
                update(a,0);
            }
            else if(in[a] > 0){ 
                if(b <= 0) update(a,b);
            }
            else if(in[a] < 0 && b > 0)
                remove(a,-1);
            in[a] = b;
        }
        else {
            pii qb = query(b),qa = query(a-1);
            int q0 = qb.ss - qa.ss;
            int qn = qb.ff - qa.ff;
            //printf("query tem %d 0s e %d negs em %d,%d\n",q0,qn,a,b);
            if(q0) printf("0");
            else if(qn&1) printf("-");
            else printf("+");
        }
    }
    printf("\n");
    }
}
