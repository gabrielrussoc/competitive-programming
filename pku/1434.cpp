#include <cstdio>
#include <algorithm>
#define eps 1e-8

using namespace std;
typedef unsigned long long num;

struct cx {
    num b,h,w,d;
} v[50004];

int main(){
    int k;
    scanf("%d",&k);
    while(k--){
        int n;
        scanf("%d",&n);
        num tot = 0, vol, maxb = 0;
        for(int i = 0; i < n; i++){
            scanf("%d %d %d %d",&v[i].b,&v[i].h,&v[i].w,&v[i].d);
            tot += v[i].w * v[i].h * v[i].d;
            maxb = max(maxb, v[i].b + v[i].h);
        }
        scanf("%llu",&vol);
        if(tot < vol)
            printf("OVERFLOW\n");
        else {
            double lo = 0, hi = maxb;
            while(hi-lo > eps){
                double tot2 = 0;
                double mid = (lo+hi)/2;
                for(int i = 0; i < n; i++){
                    if(v[i].b <= mid){
                        //printf("Caixote %d embaixo de %lf\n",i+1,mid);
                        if(v[i].b + v[i].h > mid){
                          //  printf("--mas parcialmente\n");
                            tot2 += (v[i].b + mid) * v[i].w * v[i].d;    
                        }
                        else tot2 += v[i].h * v[i].w * v[i].d;
                    }
                }
                if(tot2 <= vol) lo = mid;
                else hi = mid-eps;   
            }
            printf("%.2lf\n",lo);
        }
    }
}
