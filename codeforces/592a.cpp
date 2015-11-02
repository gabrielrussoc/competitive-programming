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

//////////////0123456789
const int N = 100;

char g[10][10];

int main() {
    for(int i = 0; i <  8; i++)
        for(int j = 0; j < 8; j++)
            scanf(" %c",&g[i][j]);

    int mina, minb;
    mina = minb = 100;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(g[j][i] == 'B') break;
            if(g[j][i] == 'W'){
                mina = min(mina,j);
                break;
            }
        }
    }
    for(int i = 0; i < 8; i++){
        for(int j = 7; j >= 0; j--){
            if(g[j][i] == 'W') break;
            if(g[j][i] == 'B'){
                minb = min(minb,7-j);
                break;
            }
        }
    }
    if(mina <= minb) puts("A");
    else puts("B");


}
