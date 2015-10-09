#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0) return false;
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    if(isPrime(n)){
        printf("1\n%d\n",n);
    }
    else if(isPrime(n-2)){
        printf("2\n2 %d\n",n-2);
    }
    else {
        int i;
        for(i = n; i > 1; i--){
            if(isPrime(i)) break;
        }
        int aux = n-i;
        for(int k = 2; k < aux; k++){
            if(isPrime(k)) {
                for(int j = 2; j < aux; j++){
                    if(isPrime(j) && k+j == aux){
                        printf("3\n%d %d %d\n",i,j,k);
                        return 0;
                    } 
                }
            }
        }   
    }
}
