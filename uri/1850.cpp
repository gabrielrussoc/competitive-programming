#include <bits/stdc++.h>
using namespace std;
typedef struct triple {
    int ff,ss,tt;
} tii;
typedef pair<int,int> pii;
int vx[] = {0,0,1,-1};
int vy[] = {1,-1,0,0};
int d[105][105][105];
char g[105][105];
tii st,end;

triple mt(int a, int b, int c){
    triple x;
    x.ff = a, x.ss = b, x.tt = c;
    return x;
}

void bfs(){
    queue<tii> q;
    q.push(st);
    d[st.ff][st.ss][st.tt] = 0;
    while(q.size()){
        pii at = q.front();
        q.pop();
        for(int k = 0; k < 4; k++){
            int nx = at.ff + vx[k];
            int ny = at.ss + vy[k];
            if(d[nx][ny]
        }
    }

}

int main(){
    for(int i = 0; i < 105; i++)
        for(int j = 0; j < 105; j++)
            for(int k = 0; k < 105; k++)
                d[i][j][k] = INT_MAX;

    for(int i = 0; i < 105; i++)
        for(int j = 0; j < 105; j++)
            g[i][j] = '#';

    char c;
    int i, j;
    i = j = 1;
    pii end;
    while((c = getchar()) != EOF){
        if(c == '@') st = tii(i,j,0);
        if(c == '*') end = pii(i,j);
        if(c == '\n') i++, j = 1;
        else g[i][j++] = c;
    }
    bfs();
}
