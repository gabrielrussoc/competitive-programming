#include <bits/stdc++.h>
using namespace std;

const int N = 3003;

int x[N], y[N], c[N], per[N];
int nx[N][4], mae[N][4];
int n;

// ^ 0
// V 1
// > 2
// < 3

void add (int i, int j, int t){
    if(t){ // vertical
        mae[j][0] = i;
        mae[i][1] = j;
    }
    else { //horizontal
        mae[i][2] = j;
        mae[j][3] = i;
    }
}

bool compx (int i, int j){
    if(x[i] == x[j]) return y[i] < y[j];
    return x[i] < x[j];
}

bool compy (int i, int j){
    if(y[i] == y[j]) return x[i] < x[j];
    return y[i] < y[j];
}

void build_list(){
    for(int i = 0; i < n; i++) per[i] = i;
    sort(per,per+n, compx);
    for(int i = 0; i < n-1; i++)
        if(x[per[i]] == x[per[i+1]]) add(per[i],per[i+1],1);
    sort(per,per+n, compy);
    for(int i = 0; i < n-1; i++)
        if(y[per[i]] == y[per[i+1]]) add(per[i],per[i+1],0);

}

void copy (){
    for(int i = 0; i < n; i++){
        nx[i][0] = mae[i][0];
        nx[i][1] = mae[i][1];
        nx[i][2] = mae[i][2];
        nx[i][3] = mae[i][3];
    }
}

void del(int i){
    if(nx[i][0] >= 0) nx[nx[i][0]][1] = nx[i][1];   
    if(nx[i][1] >= 0) nx[nx[i][1]][0] = nx[i][0];   
    if(nx[i][2] >= 0) nx[nx[i][2]][3] = nx[i][3];   
    if(nx[i][3] >= 0) nx[nx[i][3]][2] = nx[i][2];   
}

int main() {
    memset(mae,-1,sizeof mae);
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        scanf("%d %d %c",x+i,y+i,c+i);
    
    build_list();
    
    int maxi = 0;
    for(int i = 0; i < n; i++){
        copy();
        
        int at = i, res = 0, p;
        while(at != -1){
            res++;
            if(c[at] == '^') p = nx[at][0];
            else if(c[at] == 'v') p = nx[at][1];
            else if(c[at] == '>') p = nx[at][2];
            else p = nx[at][3];
            del(at);
            at = p;
        }
        maxi = max(res, maxi);
    }
    printf("%d\n",maxi);
}
