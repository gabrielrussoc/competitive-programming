#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b,a%b);
}

char v[10005];

int main(){
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d/%d",&a,&b);
        int k = 0,x;
        while(a != 1 || b != 1){
            if(b > a){
                x = a;
                a = b-a;
                b = x;
                printf("L");
            }
            else {
                x = b;
                b = a-b;
                a = x;
                printf("R");
            }
            x = mdc(a,b);
            a /= x;
            b /= x;
        }
        printf("\n");
    }
}
