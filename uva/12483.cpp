#include <bits/stdc++.h>
using namespace std;

int l, m, n;
double h;

struct tipo {
    int i, fx, fy;
};

tipo v[1005];

double dis (int ax, int ay, int bx, int by) {
    return sqrt ((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
}

bool go (int a, int b, int c, int d){
    int esc = a*c + b*d;
    if(esc > 0) return true; 
    return false;
}

int main () {
    while (scanf ("%d", &n) != EOF) {
        scanf ("%d %d", &l, &m);
        for (int i = 0; i < n; i++) {
            scanf ("%d %d %d", &v[i].i, &v[i].fx, &v[i].fy);
        }
        double a, b, d, x, y;
        double mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (i != n-1) {
                if (i % 2 == 0 && go(v[i].fx - v[i+1].fx, v[i].fy - v[i+1].fy, l-v[i+1].fx, v[i+1].i-v[i+1].fy)) {
                    a = dis (v[i].fx, v[i].fy, v[i+1].fx, v[i+1].fy);
                    b = dis (v[i].fx, v[i].fy, l, v[i+1].i);
                    d = dis (v[i+1].fx, v[i+1].fy, l, v[i+1].i);
                    double p = (a+b+d)/2;
                    h = 2*sqrt ((p*(p-a)*(p-b)*(p-d)))/d;
                } 
                
                else if (i % 2 && go(v[i].fx - v[i+1].fx, v[i].fy - v[i+1].fy, 0-v[i+1].fx, v[i+1].i-v[i+1].fy)) {
                    a = dis (v[i].fx, v[i].fy, v[i+1].fx, v[i+1].fy);
                    b = dis (v[i].fx, v[i].fy, 0, v[i+1].i);
                    d = dis (v[i+1].fx, v[i+1].fy, 0, v[i+1].i);
                    double p = (a+b+d)/2;
                    h = 2*sqrt ((p*(p-a)*(p-b)*(p-d)))/d;
                }

                else {
                    h = dis (v[i].fx, v[i].fy, v[i+1].fx, v[i+1].fy);
                }      
                mini = min (mini, h);             
            }
            if (i % 2 == 0) 
                mini = min (mini, (double) l - v[i].fx);
            else 
                mini = min (mini, (double) v[i].fx);
        }
        printf ("%.2lf\n", mini);
    }
}
