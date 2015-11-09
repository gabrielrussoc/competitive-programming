#include <bits/stdc++.h>
using namespace std;

int freq[21];
int main(){
    long long ans = 1;
    for(int i = 2; i < 21; i++){
        int n = i;
        for(int j = 2; j <= i; j++){
            int cont = 0;        
            while(n%j == 0){
                n /= j;
                cont++;
            }
            freq[j] = max(freq[j],cont);
        }
    }
    for(int i = 2; i < 21; i++) 
        if(freq[i])
           for(int j = 0; j < freq[i]; j++)
            ans *= i;

    for(int i = 1; i < 21; i++) if(ans%i) cout << "ops " << i << endl;
    cout << ans << endl;
}
