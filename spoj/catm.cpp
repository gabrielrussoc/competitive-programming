#include <bits/stdc++.h>
using namespace std;

struct par { 
    int i, j;
};

int dist (par a, par b){
    return abs(a.i-b.i) + abs(a.j-b.j);
}

par mp (int a, int b){
    par x;
    x.i = a, x.j = b;
    return x;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    par s1,s2,s3,s4;
    int t;
    scanf("%d",&t);
    while(t--){
        par r,g1,g2;
        scanf("%d %d %d %d %d %d",&r.i,&r.j,&g1.i,&g1.j,&g2.i,&g2.j);
        s1 = mp(1,r.j);
        s2 = mp(r.i,m);
        s3 = mp(n,r.j);
        s4 = mp(r.i,1);
        if(dist(r,s1) < dist(g1,s1) && dist(r,s1) < dist(g2,s1))
            puts("YES");
        else if(dist(r,s2) < dist(g1,s2) && dist(r,s2) < dist(g2,s2))
            puts("YES");
        else if(dist(r,s3) < dist(g1,s3) && dist(r,s3) < dist(g2,s3))
            puts("YES");
        else if(dist(r,s4) < dist(g1,s4) && dist(r,s4) < dist(g2,s4))
            puts("YES");
        else puts ("NO");
    }
}
