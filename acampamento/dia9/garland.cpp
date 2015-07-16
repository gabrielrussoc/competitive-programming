#include <cstdio>
#include <cstring>

using namespace std;

int main(){

    int q[28],t[28];
    char v1[1003],v2[1003];
    for(int i = 0; i < 28; i++)
        q[i] = t[i] = 0;

    scanf("%s %s",v1,v2);
    int n1,n2;
    n1 = strlen(v1);
    n2 = strlen(v2);

    for(int i = 0; i < n1; i++)
        t[v1[i]-'a']++;
    for(int i = 0; i < n2; i++)
        q[v2[i]-'a']++;


    int ans = 0;
    for(int i = 0; i < 26; i++){
        if(q[i] && !t[i]){
            printf("-1\n");
            return 0;
        }
        if(t[i] >= q[i]) ans += q[i];
        else ans += t[i];   
    }

    printf("%d\n",ans);

}
