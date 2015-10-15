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
typedef long long ll;

const int N = 1100000;

ll freq[N];

int main() {
    memset(freq,0,sizeof freq);
    int n;
    scanf("%d",&n);
    int a;
    for(int i = 0; i < n; i++){
        scanf("%d",&a);
        freq[a]++;
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        freq[i+1] += freq[i]/2;
        ans += freq[i] % 2;
    }
    printf("%d\n",ans);
}
