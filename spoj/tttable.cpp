#include <bits/stdc++.h>
#define A 0
#define B 1
#define SAIDA 0
#define CHEGADA 1

using namespace std;

struct evento{
    int hora;
    int esta;
    int tipo;
} v[409];


bool comp(evento i, evento j){
    if (i.hora != j.hora)  return (i.hora < j.hora);
    return i.tipo > j.tipo;
}


/*  estacao: 0 é A, 1 é B
    tipo: 0 é saída, 1 é chegada */

int main(){

    int n, c = 1;
    scanf("%d",&n);
    while(c <= n){
        int t,na,nb;
        scanf("%d %d %d",&t,&na,&nb);
        for(int i = 0; i < 2*na; i += 2){
            int h,m;
            scanf("%d:%d",&h,&m);
            v[i].hora = 60*h + m;
            v[i].esta = A;
            v[i].tipo = SAIDA;    
            scanf("%d:%d",&h,&m);
            v[i+1].hora = 60*h + m + t;
            v[i+1].esta = B;
            v[i+1].tipo = CHEGADA;
        }
        for(int i = 2*na; i < 2*(na+nb); i+= 2){
            int h,m;
            scanf("%d:%d",&h,&m);
            v[i].hora = 60*h + m;
            v[i].esta = B;
            v[i].tipo = SAIDA;    
            scanf("%d:%d",&h,&m);
            v[i+1].hora = 60*h + m + t;
            v[i+1].esta = A;
            v[i+1].tipo = CHEGADA;
        }
        sort(v,v+2*(na+nb),comp);
        int qa, qb;
        int ansa, ansb;
        qa = qb = ansa = ansb = 0;
        for(int i = 0; i < 2*(na+nb); i++){
            if(v[i].tipo == CHEGADA){
                if(v[i].esta == A) qa++;
                else qb++;
            } else {
                if(v[i].esta == A){
                    if(qa) qa--;
                    else ansa++;
                } else {
                    if(qb) qb--;
                    else ansb++;
                }
            }
               
        }
        printf("Case #%d: %d %d\n",c++,ansa,ansb);
    }
}
