#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n;
    scanf("%d", &n);
    queue<int> q;
    for(int i = 0; i < n; i++) {
        q.push(i);
    }
    for(int i = 0; i < n; i++) q.push(n+i);


    if(n == 1) {
        printf("2\n1A 0X\n1B 0X\n");
        return 0;
    }

    printf("%d\n", n);
    while(!q.empty()) {
        int p = q.front() % n + 1;
        int l = q.front() / n;
        char c = 'A' + l;
        q.pop();
        printf("%d%c ", p, c);
        p = q.front() % n + 1;
        l = q.front() / n;
        c = 'A' + l;
        q.pop();
        printf("%d%c\n", p, c);
    }
}

