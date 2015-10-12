#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;
typedef pair<int,int> pii;
pii cand[2000000];

bool ok (double f){
    return ((f-(int)floor(f+eps)) <= eps);
}

int main(){
    for(int i = 1; i < 126; i++)
        for(int j = i; j < 593; j++)
            for(int k = j; k < 890; k++){
                double a,b,c,d;
                a = i/100.0; b = j/100.0; c = k/100.0;
                d = (a+b+c)/(a*b*c -1);
                if(ok(100*d) && d >= c-eps && a+b+c+d <= 20+eps){
                    printf("%.2f %.2f %.2f %.2f\n",a,b,c,d);
               }
            }





}
