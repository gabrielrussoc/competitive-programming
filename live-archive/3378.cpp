#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#define x first
#define y second
#define pii pair<int,int>

using namespace std;

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b,a%b);
}

int main(){

    pii v[1003];

    int n, tc = 1;
    while(scanf("%d",&n), n != 0){
        for (int i = 0; i < n; i++)
            scanf("%d %d",&v[i].first, &v[i].second);

        int maxi = 0;
        for(int i = 0; i < n; i++){
            map<pii,int> freq;
            int cagado = 0;
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(v[i].x == v[j].x){
                    cagado++;
                    maxi = max(cagado,maxi);
                }
                else{ 
                    pii k;
                    k.second = v[i].x - v[j].x;
                    k.first = v[i].y - v[j].y;
                    int p = mdc(abs(k.first),abs(k.second));
                    k.first /= p;
                    k.second /= p;    
                    freq[k]++;
                    maxi = max(maxi,freq[k]);
                }
            }
        }
        maxi++;
        if(maxi < 4) maxi = 0;

        printf("Photo %d: %d points eliminated\n",tc++,maxi);
        
    }


}

