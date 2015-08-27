#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char abc[30];
char in[105][105];
int n;

int val(char c){
    for(int i = 0; i < 26; i++)
        if(abc[i] == c) return i;
}

void repl(int j, int i){
    char aux = abc[i];
    for(int k = i; k < j; k++)
       abc[k] = abc[k+1];
    abc[j] = aux;
}

bool solved(){
    for(int i = 0; i < n-1; i++){
        int t1 = strlen(in[i]);
        int t2 = strlen(in[i+1]);
        for(int j = 0; j < min(t1,t2); j++){
            if(val(in[i][j]) > val(in[i+1][j]))
               return false;
            else break;
        }
    }
    return true;
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s",in[i]);
    }

    for(int i = 0; i < 26; i++)
        abc[i] = 'a'+i;
    abc[26] = '\0';


    for(int i = 0; i < n-1; i++){
        int t1,t2;
        t1 = strlen(in[i]);
        t2 = strlen(in[i+1]);
        bool yay = false;
        for(int j = 0; j < min(t1,t2); j++){
            if(in[i][j] == in[i+1][j]) continue;
            if(val(in[i][j]) > val(in[i+1][j]))
                repl(val(in[i][j]),val(in[i+1][j]));
            yay = true;
            break;
        }
        if(!yay && t1 > t2){
            printf("Impossible\n");
            return 0;
        }
    }
    if(solved()) printf("%s\n",abc);
    else printf("Impossible\n");
}
