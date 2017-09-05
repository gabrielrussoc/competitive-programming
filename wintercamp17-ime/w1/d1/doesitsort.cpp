#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 400;

const int k = 20;
int v[k], o[k];
struct query {
    bool sort;
    int i, j;  
    query() {}
    query(bool sort, int i, int j) : sort(sort), i(i), j(j) {}
} q[N];

void check() {
    for(int i = 1; i < k; i++) {
        if(v[i] < v[i-1]) {
            puts("incorrect");
            for(int j = 0; j < k; j++) printf("%d ", o[j]);
            putchar('\n');
            exit(0);
        }
    }
}

int main() {
    for(int i = 0; i < k; i++) v[i] = i;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a, b;
        string s;
        cin >> s >> a >> b;
        q[i].sort = s == "sort";
        q[i].i = a;
        q[i].j = b;
    }
    srand(time(NULL));
    for(int p = 0; p < 1e6; p++){
        next_permutation(v, v+k);
        for(int i = 0; i < k; i++) o[i] = v[i];
        for(int i = 0; i < n; i++) {
            if(q[i].sort) sort(v+q[i].i, v + q[i].j);
            else if(v[q[i].i] > v[q[i].j]) swap(v[q[i].i], v[q[i].j]);
        }
        check();
    }
    puts("correct");
}

