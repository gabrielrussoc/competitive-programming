#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 100005;

int t, n, v[N], odd[N], even[N], oc, ec;

int main() {
    int tc = 1;
    scanf("%d", &t);
    while(t--) {
        oc = ec = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            if(i&1) scanf("%d", &odd[oc++]);
            else scanf("%d", &even[ec++]);
        }
        sort(odd, odd+oc);
        sort(even, even+ec);
        oc = ec = 0;
        for(int i = 0; i < n; i++) {
            if(i&1) v[i] = odd[oc++];
            else v[i] = even[ec++];   
        }
        int wrong = -1;
        for(int i = 0; i < n-1 && wrong == -1; i++)
            if(v[i] > v[i+1])
                wrong = i;
        printf("Case #%d: ", tc++);
        if(wrong == -1) puts("OK");
        else printf("%d\n", wrong);
    }
}

