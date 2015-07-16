#include <cstdio>

using namespace std;

int n;
double a, d;

double resto(double x, double y){

    while(x > y)
        x -= y;
    
    return x;
}

int main(){

    scanf("%lf %lf %d", &a, &d, &n);
    
    double x = 0, y = 0;
    int cont = 0;
    double aux, dis;
    
    d = resto(d, 4*a);
    while(n--){
        aux = d;
        while(aux > 0){
        
            if(cont == 0){
                dis = a - x;
                if(aux > dis){
                    x = a;
                    aux -= dis;
                    cont++;
                }
                else{
                    x += aux;
                    aux = 0;
                    printf("%.10f %.10f\n", x, y);
                    break;
                }
            }
            if(cont == 1){
                dis = a - y;
                if(aux > dis){
                    y = a;
                    aux -= dis;
                    cont ++;
                }
                else{
                    y += aux;
                    aux = 0;
                    printf("%.10f %.10f\n", x, y);
                    break;
                }
            }
            if(cont == 2){
                dis = x;   
                if(aux > dis){
                    x = 0;
                    aux -= dis;
                    cont++;
                }
                else{
                    x -= aux;
                    aux = 0;
                    printf("%.10f %.10f\n", x, y);
                    break;
                }
            }
            if(cont == 3){
                dis = y;
                if(aux > dis){
                    y = 0;
                    aux -= dis;
                    cont = 0;
                }
                else{
                    y -= aux;
                    aux = 0;
                    printf("%.10f %.10f\n", x, y);
                    break;
                }
            }
        }
    }
}
