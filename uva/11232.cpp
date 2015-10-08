#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);

int main(){
    int h,w;
    while(scanf("%d %d",&h,&w) && h != 0){
        if(w > h) swap(w,h);
        double x =  (double) h/(PI+1);
        if(x > w) x = w;
        double ans1 = (double) PI/4*w*x*x;
        double ans2 = (double) PI/4 * w/PI*w/PI * (h-w/PI);
        printf("%.3lf\n",fmax(ans1,ans2));
    }

}
