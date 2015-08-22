#include <cstdio>
#include <algorithm>
#define pii pair<int,int>
#define MAXN 100005
#define mp make_pair

using namespace std;

int b[MAXN],s[MAXN];

int main(){

    for(int i = 0; i < MAXN; i++)
        b[i] = s[i] = 0;

    int n,S;
    scanf("%d %d",&n,&S);

    int p,q;
    char d;
    for(int i = 0; i < n; i++){
        scanf(" %c %d %d",&d,&p,&q);
        if(d == 'B')
            b[p] += q;
        else
            s[p] += q;
    }

    int k = 0, j = 0;
    pii buy[1003],sell[1003];
    for(int i = 0; i < MAXN; i++){
        if(b[i]) buy[k++] = mp(-i,b[i]); 
        if(s[i]) sell[j++] = mp(i,s[i]);
    }

    sort(buy,buy+k);
    sort(sell,sell+j);

    int t = min(j,S);
    for(int i = 0; i < t; i++)
        sell[i].first = -sell[i].first;
    sort(sell,sell+t);
    for(int i = 0; i < t; i++)
        printf("S %d %d\n",-sell[i].first,sell[i].second);
    t = min(k,S);
    for(int i = 0; i < t; i++)
        printf("B %d %d\n",-buy[i].first,buy[i].second);



}
