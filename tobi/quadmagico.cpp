#include <cstdio>
#include <iostream>

int m[3][3];
int ans;
using namespace std;

int calc(){
    //rows
    int maxi = 0;
    for(int i = 0; i < 3; i++){
        int ans = 0;
        for(int j = 0; j < 3; j++)
            ans += m[i][j];
        maxi = max(ans,maxi);
    }
    for(int i = 0; i < 3; i++){
        int ans = 0;
        for(int j = 0; j < 3; j++)
            ans += m[j][i];
        maxi = max(ans,maxi);
    }

    maxi = max(maxi,m[0][0]+m[1][1]+m[2][2]);
    maxi = max(maxi,m[2][0]+m[1][1]+m[0][2]);

    return maxi;
}

void fill(int i, int j){
    int p = 0;
    p = max(p,m[i][0] + m[i][1] + m[i][2]);
    p = max(p,m[0][j] + m[1][j] + m[2][j]);
    if(i == j) p = max(p,m[0][0] + m[1][1] + m[2][2]);
    if(i+j == 2) p = max(p,m[2][0] + m[1][1] + m[0][2]);
    m[i][j] = ans-p;
}

void solve(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(m[i][j] == 0) fill(i,j);
            printf("%d%c",m[i][j],j == 2 ? '\n' : ' ');
        }
    }
}


int main(){

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cin >> m[i][j];

    if(m[0][0] == m[1][1] && m[1][1] == m[2][2] && m[2][2] == 0){
        bool ok = false;
        int b = 1;
        int k, a, c;
        while(!ok){
            m[1][1] = b;
            k = m[0][1] + m[1][1] + m[2][1];
            a = k - m[1][0] - m[2][0];
            c = k - m[2][0] - m[2][1];
            if(a+b+c == k && a > 0 && b > 0){
                m[0][0] = a;
                m[2][2] = c;
                ok = true;
            }
            b++;
        }
        solve();
    }

    else if(m[2][0] == m[1][1] && m[1][1] == m[0][2] && m[0][2] == 0){
        bool ok = false;
        int b = 1;
        int k, a, c;
        while(!ok){
            m[1][1] = b;
            k = m[0][1] + m[1][1] + m[2][1];
            a = k - m[0][0] - m[1][0];
            c = k - m[1][2] - m[2][2];
            if(a+b+c == k && a > 0 && b > 0){
                m[2][0] = a;
                m[0][2] = c;
                ok = true;
            }
            b++;
        }
        solve();
    }
    else {
        ans = calc();
        solve();
    }
}
