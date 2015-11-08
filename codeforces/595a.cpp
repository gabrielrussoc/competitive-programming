#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define modn 1000000007
#define ff first
#define ss second
using namespace std;
typedef unsigned long long ull;

//////////////0123456789
const int N = 100;

int n,m;

int main(){
    scanf("%d %d",&n,&m);
    int ans = 0;
    for(int i = 0; i <n; i++)
        for(int i = 0; i < m; i++){
            int a,b;
            scanf("%d %d",&a,&b);
            if(a || b) ans++;
        }
    printf("%d\n",ans);
}
