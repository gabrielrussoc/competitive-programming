#include <cstdio>
#include <algorithm>
#define pii pair<int,int>

using namespace std;

int p[260];
pii num[14];

void coord(){
    for(int i = 0; i < 9; i++){
        num[i+1].first = i/3;
        num[i+1].second = i%3;
    }
    num[0].first = 3;
    num[0].second = 1;
}

bool pode(int i){
    int aux = i, cont = 0;
    char s[5];
    while(aux){
        aux /= 10;
        cont++;
    }
    int t = cont;
    s[t] = '\0';
    while(i){
        s[cont-1] = (i%10)+'0';
        i /= 10;
        cont--;   
    }
    int last = s[0]-'0';
    for(int j = 1; j < t; j++){
        int x = s[j]-'0';
        if(num[x].first < num[last].first || num[x].second < num[last].second) return false;
        last = x;
    }
    return true;
}

int pre(){
    int j = 0;
    for(int i = 0; i <= 209; i++){
        if(pode(i)) 
            p[j++] = i;
    }
    return j;
}

int main(){
    coord();
    int n = pre();
    int t,k;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&k);
        int mini = 12345, resp;
        for(int i = 0; i < n; i++){
            if(abs(p[i]-k) <= mini){
                mini = abs(p[i]-k);
                resp = p[i];
            }
        }
        printf("%d\n",resp);
    }

}
