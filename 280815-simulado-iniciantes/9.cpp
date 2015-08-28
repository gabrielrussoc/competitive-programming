#include <cstdio>
#include <set>
#define pii pair<int,int>
#define mp make_pair

using namespace std;

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b,a%b);
}

int v[1234];
set<pii> s;

int main(){

    
    for(int k = 1; k < 1003; k++){
        for(int i = 0; i <= k; i++){            
            int b = mdc(i,k);
            s.insert(mp(k/b,i/b));
        }   
        v[k] = s.size()*2 -1; 
    }

    int c, n;
    scanf("%d",&c);
    for(int t = 1; t <= c; t++){
        scanf("%d",&n);
        printf("%d %d %d\n",t,n,v[n]);
    }

}
