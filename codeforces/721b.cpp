#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 123;
int n, k;
string s[N], p;

bool comp(string a, string b) {
    int na = a.length();
    int nb = b.length();
    if(na == nb) return a.compare(p) == 0;
    return na < nb;
}

bool comp2(string a, string b) {
    int na = a.length();
    int nb = b.length();
    if(na == nb) return a.compare(p) != 0;
    return na < nb;
}

int get(){
    int t = 0;
    int w = 0;
    for(int i = 0; i < n; i++) {
        t++;
        if(s[i].compare(p) == 0) return t;
        w++;
        if(w == k) {
            w = 0;
            t += 5;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++) cin >> s[i];
    cin >> p;
    stable_sort(s,s+n, comp);
    int best = get();
    stable_sort(s,s+n, comp2);
    int worst = get();
    printf("%d %d\n",best,worst);
}

