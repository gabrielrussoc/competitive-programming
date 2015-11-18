#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int uf[105], wf[105];

int find(int i){
    if(uf[i] == i) return i;
    return uf[i] = find(uf[i]);
}

void join(int i, int j){
    i = find(i); j = find(j);
    if(i == j) return;
    if(wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    uf[i] = j;
}

int main (){
    int n;
    char ans[105][105];
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        uf[i] = i; wf[i] = 1;
        for(int j = 0; j < n; j++)
            ans[i][j] = '0';
    }
    ll a,d;
    ll add, rem;
    add = rem = 0;
    cin >> d >> a;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            char c;
            scanf(" %c",&c);
            if(i >= j) continue;
            if(c == '1'){
                if(find(i) != find(j)){
                    join(i,j);
                }
                else {
                    rem++;
                    ans[i][j] = ans[j][i] = 'd';
                }
            }
        }
    int x = find(0);
    for(int i = 1; i < n; i++)
        if(uf[i] == i && i != x){
            ans[x][i] = ans[i][x] = 'a';
            add++;
        }
    printf("%lld\n",rem*d + add*a);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%c",ans[i][j]);
        printf("\n");
    }
} 
