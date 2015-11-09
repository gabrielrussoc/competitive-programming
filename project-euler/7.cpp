#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
int p[N], v[N];

void crivo(){
    for(int i = 2; i*i < N; i++){
        if(!p[i]){
            for(int j = i*i; j < N; j+=i)
                p[j] = 1;
        }
    }
    int x = 1;
    for(int i = 2; i < N; i++)
        if(!p[i]) v[x++] = i;
}

int main(){
    crivo();
    cout << v[10001] << endl;
}
