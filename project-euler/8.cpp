#include <bits/stdc++.h>
using namespace std;

int main(){
    long long v[1004];
    char c;
    for(int i = 0; i < 1000; i++) {
        scanf(" %c",&c);
        v[i] = c-'0';
    }
    long long ans = 0;
    for(int i = 0; i < 1000-13; i++){
        long long tmp = 1;
        for(int j = i; j < i+13; j++) tmp *= v[j];
        ans = max(ans,tmp);
    }
    cout << endl << ans << endl;

}
