#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const double eps = 1e-9;

struct point {
    int x, y;
    int i;
} v[N];


long double PI = 3.14159265359;

long double ang (point a){
    long double x = atan2(a.y,a.x);
    if(x < 0.0) x += 2*PI;
    return x;
}

bool comp (point a, point b){
    return ang(a) < ang(b);
}
int main(){
    int n;
    scanf("%d",&n);
    int a, b;
    for(int i = 0; i < n; i++){
        scanf("%d %d",&v[i].x,&v[i].y);
        v[i].i = i+1;
    }
    long double ans = 100;
    sort(v,v+n,comp);
    for(int i = 0; i < n - 1; i++){
        long double dif = ang(v[i+1]) - ang(v[i]);
        dif = min(dif,2*PI -dif);
        if(dif < ans){
            ans = dif;
            a = v[i].i;
            b = v[i+1].i;
        }
    }
    long double dif = ang(v[n-1]) - ang(v[0]);
    dif = min(dif,2*PI -dif);
    if (dif < ans){
        a = v[0].i;
        b = v[n-1].i;
    }
    printf("%d %d\n",a,b);

}
