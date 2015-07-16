#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    int m[110][110];

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> m[0][i];

    for(int i = 0; i < n; i++){
         for(int j = 0; j < m[0][i];j++){
            cin >> x;
             m[1][i] += x;
        }
    }
    
    int mini = 1000000;
    for(int i = 0; i < n; i++){
        m[2][i] = 15*m[0][i] + 5*m[1][i];
        if(m[2][i] < mini)
            mini = m[2][i];
    }

    cout << mini << endl;
}
