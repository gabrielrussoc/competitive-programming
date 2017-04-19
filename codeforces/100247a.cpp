#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 5;

int n;
vector<int> v[N], ans;
set<pii> s1, s2;

int main() {
    scanf(" %d", &n);
    if(n == 1) {
        puts("1\n1");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int a;
            scanf(" %d", &a);
            v[i].pb(a);
        }
        sort(v[i].begin(), v[i].end());
        s1.insert(pii(v[i][0], v[i][1]));
        s2.insert(pii(v[i][1], v[i][0]));
    }

    for (int i = 0; i < n; i++) {
        s1.erase(s1.find(pii(v[i][0], v[i][1])));
        s2.erase(s2.find(pii(v[i][1], v[i][0])));

        pii a, b, best;
        a = *s1.rbegin();
        b = *s2.rbegin();
        best = pii(max(a.ff, b.ss), max(a.ss, b.ff));
        if (v[i][1] > best.ff && v[i][2] > best.ss)
            ans.pb(i + 1);

        s1.insert(pii(v[i][0], v[i][1])), s2.insert(pii(v[i][1], v[i][0]));
    }

    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
    printf("\n");
}