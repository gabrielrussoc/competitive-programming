#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n, x;
    set<int> s;
    scanf("%d",&n);
    int qt = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        s.insert(x);
        while(!s.empty() && *(s.rbegin()) >= n-qt) {
            int a = *(s.rbegin());
            printf("%d ", a);
            s.erase(a);
            qt++;
        }
        putchar('\n');
    }
}

