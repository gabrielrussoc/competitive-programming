#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define ff first
#define ss second
using namespace std;
typedef long long ll;

//////////////0123456789
const int N = 100005;
const int modn = 1000000007;

int main(){
    int w[10], m[10];
    int p[] = {500,1000,1500,2000,2500};
    for(int i = 0; i < 5; i++) scanf("%d",m+i);
    for(int i = 0; i < 5; i++) scanf("%d",w+i);
    int hs, hu;
    scanf("%d %d",&hs,&hu);
    int ans = 0;
    for(int i = 0; i < 5; i++){
        ans += max((p[i]*3)/10, p[i]  - (p[i]*m[i])/250 - 50*w[i]);     
    }
    printf("%d\n",ans+100*hs - 50*hu);
}
