#include <cstdio>

using namespace std;

int main(){
    
    int v[104];
    int n,d,l;
    scanf("%d %d %d",&n,&d,&l);


    int k = 0;
    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            v[i] = l;
            k += l;
        }
        else {
            v[i] = 1;
            k--;
        }
    }
    int mini = (n/2 + n%2) - (n/2)*l;
    int maxi = (n/2 + n%2)*l - n/2;

    if(d > maxi || d < mini){
        printf("-1\n");
        return 0;
    }

    for(int i = 0; i < n; i++){
        if(i%2 == 0){
            while(v[i] > 1 && k != d){
                v[i]--;
                k--;
            }
        } else { 
            while(v[i] < l && k != d){
                v[i]++;
                k--;
            }
        }
        if(k == d) break;
    }
    for(int i = 0; i < n; i++)
        printf("%d%c",v[i], i == n-1 ? '\n' : ' ');


}
