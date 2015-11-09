#include <bits/stdc++.h>
using namespace std;

int main(){
    int i,j,c;
    for(i = 1; i < 1000; i++){
        for(j = i+1; j < 1000; j++){
            c = 1000-j-i;
            if(c <= j) break;
            if(i*i + j*j == c*c) {
                printf("%d\n",i*j*c);
                return 0;
            }
        }
    }
}
