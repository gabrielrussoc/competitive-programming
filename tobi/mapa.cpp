#include <cstdio>
#include <vector>
#define pb push_back
using namespace std;

const int N = 100005;
long long n,a,b,c;

vector<int> adj[N];
bool seen[N];

long long dfs(int j){
    if(seen[j]) return 0;
    seen[j] = true;
    int k = adj[j].size();
    long long ans = 1;
    for(int i = 0; i < k; i++){
        ans += dfs(adj[j][i]);
    }   
    return ans;
}

int main(){

    scanf("%lld",&n);
    for(int i = 1; i <= n; i++) seen[i] = false;
    for(int i = 0; i < n-1; i++){
        scanf("%lld %lld %lld",&a,&b,&c);
        if(c == 0){
            adj[a].pb(b);
            adj[b].pb(a);
        }
    }
    long long tot = n*(n-1)/2;
    long long cag;
    for(int i = 1; i <= n; i++){
        cag = dfs(i);
        tot -= cag*(cag-1)/2;
    }
    printf("%lld\n",tot);
}
