#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-8;
const int inf = INT_MAX;
const int modn = 1000000007;

//////////////0123456789
const int N = 100005;

int n,m,k;

int memo[35][35][55];

int solve(int i, int j, int r){
    if(r < 0) return 123456;
    if(!i || !j || r == 0) return 0;
    int &me = memo[i][j][r];
    if(me != -1) return me;
    me = solve(0,0,r-(i*j));
    for(int l = 1; l < i; l++)
        me = min(j*j+solve(i-l,j,r),min(j*j + solve(l,j,r),min(me,j*j + solve(l,j,r) + solve(i-l,j,r))));
    for(int l = 1; l < j; l++)
        me = min(i*i+solve(i,j-l,r),min(i*i + solve(i,l,r),min(me,i*i + solve(i,l,r) + solve(i,j-l,r))));
    return me;
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&k);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                for(int p = 0; p <= k; p++)    
                    memo[i][j][p] = -1;
        printf("%d\n",solve(n,m,k));
    }   
}

