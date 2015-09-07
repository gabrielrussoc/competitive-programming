#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int v[105];
char s[105];

int main(){
    scanf("%s",s);
    int t = strlen(s);
    int k = 0;
    for(int i = 0; i < t; i++)
        if(s[i] != '+') v[k++] = s[i]-'0';
    sort(v,v+k);
    bool f = false;
    for(int i = 0; i < k; i++){
        if(f) printf("+");
        printf("%d",v[i]);
        f = true;
    }
}
