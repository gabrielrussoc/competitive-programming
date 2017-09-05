#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int MAXN = 1123;

int n, m;
char st[MAXN][MAXN];
char M[MAXN][MAXN];

vector<int> vi, vj;

bool valid(int i, int j){
    return (i >=0 && j >= 0 && i < n && j < m);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--){
        vi.clear();
        vj.clear();
        int nn, mm;
        scanf("%d%d%d%d", &n, &m, &nn, &mm);
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                scanf(" %c", &M[a][b]);
            }
        }
        int i = -1, j = -1;
        for(int a=0;a<nn;a++){
            for(int b=0;b<mm;b++){
                scanf(" %c", &st[a][b]);
                if(st[a][b] == 'x'){
                    if(i == -1){
                        vi.pb(0);
                        vj.pb(0);
                    }
                    else{
                        vi.pb(a - i);
                        vj.pb(b - j);
                    }
                    i = a;
                    j = b;
                }
            }
        }
        int erou = 0;
        for(int a=0;erou == 0 && a<n;a++){
            for(int b=0;erou == 0 && b<m;b++){
                if(M[a][b] == 'x'){
                    int i = a;
                    int j = b;
                    for(int p=0;p<vi.size();p++){
                        i += vi[p];
                        j += vj[p];
                        if(!valid(i, j) || M[i][j] != 'x'){
                            erou = 1;
                            break;
                        }
                        M[i][j] = '.';
                    }
                }
            }
        }
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                if(M[a][b] == 'x')
                    erou = 1;
            }
        }
        if(erou)
            puts("NIE");
        else
            puts("ANO");
    }
}

