#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
#define pii pair<int,int>
#define mp make_pair
#define ff first
#define ss second
using namespace std;

int c,f;
int m[1001][52];
pii v[55];


int pd(int w, int i){
    if(w < 0) return INT_MIN;
    if(i == f || w == 0) return 0;
    int &k = m[w][i];
    if(k != -1) return k;
    k = max(v[i].ss + pd(w-v[i].ff,i+1),pd(w,i+1));
    return k;
}


int main(){
    
    int tc = 1;
    while(cin >> c >> f && c != 0 && f != 0){
        memset(m,-1,sizeof m);
        for(int i = 0; i < f; i++)
            cin >> v[i].ff >> v[i].ss;
        cout << "Teste " << tc++ << endl;
        cout << pd(c,0) << endl << endl;
    }



}
