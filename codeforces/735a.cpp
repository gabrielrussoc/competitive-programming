#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 123;
int n, k, bg, tgt;
int v[N];

void suc(){
    puts("YES");
    exit(0);
}

int main() {
    scanf("%d %d",&n, &k);
    for(int i = 0; i < n; i++){
        scanf(" %c", v+i);
        if(v[i] == 'G') bg = i;
        if(v[i] == 'T') tgt = i;
    }
    if(bg > tgt) { //esq
        for(int i = bg; i >= 0; i -= k) {
            if(v[i] == 'T') suc();
            else if(v[i] == '#') break;
        }
    } else {
        for(int i = bg; i < n; i += k) {
            if(v[i] == 'T') suc();
            else if (v[i] == '#') break;
        }
    }
    puts("NO");
}

