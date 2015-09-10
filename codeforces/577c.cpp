#include <bits/stdc++.h>

using namespace std;

int p[1234];
long long v[1234];
int k = 0;

void crivo(){
    for(int i = 2; i <= 1000; i++){
        if(!p[i]){
            v[k++] = i;
            for(int j = i*i; j <= 1000; j += i)
                p[j] = 1;
        }
    }
}

int main(){
    
   
    memset(p,0,sizeof p);
    crivo();
    long long n;
    cin >> n;
    long long i = 0;
    vector<long long> ans;
    while(v[i] <= n && i < k){
        long long aux = v[i];
        while(v[i] <= n){
            ans.push_back(v[i]);
            v[i] *= aux;
        }
        i++;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}
