#include <bits/stdc++.h>
#define pcc pair<char,char>
#define mp make_pair
#define ff first
#define ss second

using namespace std;

pcc m[205][205];
int v[205];
int l,c;

int main(){
    while(scanf("%d %d",&l,&c) != EOF){
        map<pcc,int> var;
        map<pcc,int>:: iterator it;
        for(int i = 0; i < l; i++){
            for(int j = 0; j < c; j++){
                char a,b;
                scanf(" %c%c",&a,&b);
                m[i][j] = mp(a,b);
            }
            scanf("%d",v+i);
        }
        for(int i = 0; i < c; i++)
            scanf("%d",v+i+l);

        for(int i = 0; i < c; i++){
            for(int j = 0; j < l; j++){
                m[i+l][j] = m[j][i];
            }
        }
        bool go = true;
        while(go){
            go = false;
            for(int i = 0; i < l+c; i++){
                int k;
                if(i < l) k = c;
                else k = l;
                int sum, uk, j;
                pcc at;
                uk = sum = j = 0;
                for(j = 0; j < k; j++){
                    if(var.find(m[i][j]) == var.end()){
                        if(uk == 0)
                            at = m[i][j];
                        else
                            if(m[i][j] != at) break;
                        uk++;
                    }
                    else sum += var[m[i][j]];
                }
                if(uk && j == k){
                    var[at] = (v[i]-sum)/uk;
                    go = true;
                }
            }
        }
        for(it = var.begin(); it != var.end(); it++)
            printf("%c%c %d\n",(it->ff).ff,(it->ff).ss,it->ss);
    }

}
