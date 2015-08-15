#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define eps 1e-8
#define pii pair<int,int>
#define pll pair<long long,long long>
#define inf INT_MAX
#define modn 1000000007
typedef long long ll;

using namespace std;

struct cand {
    int q;
    int ind;
    int ind2;
};

cand vote[105][105];
cand win[105];
int freq[105];

bool comp1 (cand a, cand b){
    if(a.q == b.q) return a.ind < b.ind;
    return a.q > b.q;
}

bool comp2 (cand a, cand b){
    if(a.q == b.q) return a.ind > b.ind;
    return a.q > b.q;
}

int main(){

    for(int i = 0; i < 105; i++)
        freq[i] = 0;

    int n,m,k = 0;
    scanf("%d %d",&n, &m);

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d",&vote[i][j].q);
            vote[i][j].ind = j;

        }
    }
    
    for(int i = 0; i < m; i++){
        sort(vote[i],vote[i]+n,comp1);
        win[i] = vote[i][0];
    }
    int maxi = -1,ans;
    int j = 0;
    for(int i = 0; i < m; i++)
        freq[win[i].ind]++;

    for(int i = 0; i < n; i++){
        if(freq[i] > maxi) {
            maxi = freq[i];
            ans = i;
        }
    }   
    printf("%d\n",ans+1);

}