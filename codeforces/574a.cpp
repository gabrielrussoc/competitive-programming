#include <cstdio>

using namespace std;

int v[109];

int main(){

    int n;
    scanf("%d",&n);
    int j, maxi = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d",v+i);
        if(v[i] >= maxi) { 
            maxi = v[i];
            j = i;
        }
    }

    int ans = 0;

    while (j != 0) {
        ans++;
        v[0]++;
        v[j]--;
        maxi = 0;
        for(int i = 0; i < n; i++) {
            if(v[i] >= maxi) { 
                maxi = v[i];
                j = i;
            }
        }
    }
    printf("%d\n",ans);

}