#include <cstdio>
#define MAXN 100005

using namespace std;

int freq[MAXN], in[MAXN], livre[MAXN];


int main(){
    
    for(int i = 0; i < MAXN; i++)
        freq[i] = 0;

    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&in[i]);
        freq[in[i]]++;
    }

    int j = 0;
    for(int i = 1; i <= n; i++){
        if(!freq[i])
            livre[j++] = i;
    }

    int p = 0;

    for(int i = 0; i < n; i++){
        if(in[i] > n || freq[in[i]] > 1){
            freq[in[i]]--;
            in[i] = livre[p];
            p++;
        }
        printf("%d ",in[i]);
    }
    printf("\n");
}