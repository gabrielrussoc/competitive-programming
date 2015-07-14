#include <bits/stdc++.h>
#define pb push_back
#define MAX 1000007

using namespace std;

struct dist {
    int p;
    int u;
} v[MAX];


int main(){

    int f[MAX];
    vector<int> cand;
    
    for(int i = 0 ; i < MAX; i++)
        f[i] = v[i].p = v[i].u = 0; 
    

    int n, max = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d",&a);
        f[a]++;
        if(f[a] > max)
            max = f[a];
        if(v[a].p == 0)
            v[a].p = v[a].u = i+1;
        else
            v[a].u = i+1;
    }
    
    for(int i = 1; i < MAX; i++)
        if(f[i] == max) cand.pb(i);
        
    int k = cand.size();
        
    int mini = INT_MAX;
    int ans;
    for(int i = 0; i < k; i++){
        if(v[cand[i]].u - v[cand[i]].p < mini){
            mini = v[cand[i]].u - v[cand[i]].p;
            ans = cand[i];
        }
    }
    cout << v[ans].p << ' ' << v[ans].u << endl;
}
