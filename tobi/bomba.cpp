#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <climits>
#define first ff
#define second ss
#define mp make_pair
#define pb push_back
#define pii pair<int,int>

using namespace std;

vector<int> adj[505];
int d[505];
bool f[505];

int main(){

    for(int i = 0; i < 505; i++){
        f[i] = false;
        d[i] = INT_MAX;
    }

    int n,e,s,m;
    scanf("%d %d %d %d",&n,&e,&s,&m);

    for(int i = 0; i < m; i++){
        int a,b,t;
        scanf("%d %d %d",&a,&b,&t);
        adj[a].pb(b);

    }
}
