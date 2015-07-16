#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,b,l[110];

    cin >> n >> m;

    memset(l, 0, sizeof l);
    while(m--){
        cin >> b;
        for(int i = b; i <= n; i++){
            if(l[i] != 0) break;
            l[i] = b;
        }
        
    }

    for(int i = 1; i <= n; i++){
        cout << l[i] << " ";
    }
    cout << endl;
}
