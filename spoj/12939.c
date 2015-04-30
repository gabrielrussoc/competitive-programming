#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10005


int m[MAX];


int main(){
    
    int n, k, i,a,b,c,temp;
    a = 1;
    b = 0;
    
    
    scanf("%d %d",&n,&k);
    
    for(i = 0; i < k; i++){
        scanf("%d",&m[i]);
        if(m[i] > b)
            b = m[i];
    }
    
    while(a != b){
        c = (a + b+1)/2;
        
        temp = 0;
        for(i = 0; i < k; i++)
            temp += m[i]/c;
            
        if(temp >= n)
            a = c;
        else
            b = c-1;
    }
    
    printf("%d\n",a);
    
    return 0;
}