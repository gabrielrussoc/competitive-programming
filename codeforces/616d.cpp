#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N], f[N+8];
int k, n, i1,i2;

int main(){
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    int lo, hi;
    i1 = i2 = 1;
    lo = 1, hi = n;
    while (lo != hi){
        int mid = (lo+hi+1)/2;
        int at = 0;
        bool val = false;
        for(int i = 0; i < mid; i++){
            f[a[i]]++;
            if(f[a[i]] == 1) at++;
        }
        if (at <= k) {
            val = true;
            i1 = 1;
            i2 = mid;
        }
        for(int i = mid; i < n; i++){
            f[a[i-mid]]--;
            if(f[a[i-mid]] == 0) at--;
            f[a[i]]++;
            if(f[a[i]] == 1) at++;
            if(at <= k) {
                val = true;
                i1 = i-mid + 2;
                i2 = i+1;
            }
        }
        for(int i = 0; i < n; i++) f[a[i]] = 0;
        if(val) lo = mid;
        else hi = mid-1;
    }
    printf("%d %d\n",i1,i2);
}
