#include <cstdio>

int main(){
    int a,b;
    a = b = 0;
    for(int i = 1; i <= 100; i++) a += i*i;
    for(int i = 1; i <= 100; i++) b += i;
    b *= b;
    printf("%d\n",b-a);
}
