#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){

    int n, k;
    int v[1007],t[1007];
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++)
        scanf("%d",&v[i]);

    int mini = 12349, minin;

    for(int i = 0; i < n; i++){
        
        int ant = v[i];
        int ans = 0;
        for(int j = i-1; j >= 0; j--){
            if(ant - v[j] != k){
                ans++;
                ant = ant - k;
            } 
            else ant = v[j];
        } 
        if(ant <= 0) ans = 239000;
        ant = v[i];       
        for(int j = i+1; j < n; j++){
            if(v[j] - ant != k){
                ans++;
                ant = ant + k;
            }
            else ant = v[j];
        }
        if(ans < mini){
            mini = ans;
            minin = i;
        }
    }
    printf("%d\n",mini);
    for(int i = 0; i < n; i++)
        t[i] = v[i];    

    for(int j = minin-1; j >= 0; j--){
        if(t[j+1] - t[j] != k){
            t[j] = t[j+1] - k;
         } 
    }        
    for(int j = minin+1; j < n; j++){
        if(t[j] - t[j-1] != k){
            t[j] = t[j-1] + k; 
        }
    }
    for(int i = 0; i < n; i++){
        if(t[i] != v[i]){
            printf("%c %d %d\n",t[i] > v[i] ? '+' : '-',i+1,abs(t[i]-v[i]));       
        }
    }

}
