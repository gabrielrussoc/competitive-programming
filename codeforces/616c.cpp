#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[1005][1005];
int lab[1005][1005];
int uf[1005*1005], wf[1005*1005];

int find (int i){
    if (i == uf[i]) return i;
    return uf[i] = find(uf[i]);
}

void join (int i, int j){
    i = find(i); j = find(j);
    if(i == j) return;
    if(wf[i] > wf[j]) swap(i,j);
    wf[j] += wf[i];
    uf[i] = j;
}

int main(){
    scanf("%d %d",&n,&m);

    for(int i = 0; i < n*m; i++)
        uf[i] = i, wf[i] = 1;

    for(int i = 0; i < n+2; i++)
        for(int j = 0; j < m+2; j++)
            s[i][j] = '*';
    int k = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            scanf(" %c",&s[i][j]);
            lab[i][j] = k++;
        }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '.'){
                if(s[i+1][j] == '.') join(lab[i][j],lab[i+1][j]);
                if(s[i-1][j] == '.') join(lab[i][j],lab[i-1][j]);
                if(s[i][j+1] == '.') join(lab[i][j],lab[i][j+1]);
                if(s[i][j-1] == '.') join(lab[i][j],lab[i][j-1]);
            }
        }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i][j] == '.') putchar('.');
            else {
                int ans = 1, x;
                set<int> go;
                if(s[i+1][j] == '.'){
                    x = find(lab[i+1][j]);
                    if(go.find(x) == go.end()){
                        ans += wf[x];
                        go.insert(x);
                    }
                }
                if(s[i-1][j] == '.'){
                    x = find(lab[i-1][j]);
                    if(go.find(x) == go.end()){
                        ans += wf[x];
                        go.insert(x);
                    }
                }
                if(s[i][j+1] == '.'){
                    x = find(lab[i][j+1]);
                    if(go.find(x) == go.end()){
                        ans += wf[x];
                        go.insert(x);
                    }
                }
                if(s[i][j-1] == '.'){
                    x = find(lab[i][j-1]);
                    if(go.find(x) == go.end()){
                        ans += wf[x];
                        go.insert(x);
                    }
                }
                printf("%d",ans%10);
            }
        }
        putchar('\n');
    }



}
