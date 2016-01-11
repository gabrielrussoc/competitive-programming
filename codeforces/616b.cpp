#include <bits/stdc++.h>
using namespace std;

int n, m, a;

int main(){
    scanf("%d %d",&n,&m);
    int res = 0;
    for(int i = 0; i < n; i++){
        int mini = INT_MAX;
        for(int j = 0; j < m; j++){
            scanf("%d",&a);
            mini = min(mini, a);
        }
        res = max(res,mini);
    }
    printf("%d\n",res);
}
