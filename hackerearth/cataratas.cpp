#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define GNU __gnu_pbds
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
namespace GNU { typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; } 
using GNU::ordered_set;

const int N = 212345;

int n, k;
ordered_set s;
int w[N];

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", w+i);
    for(int i = 0; i < k; i++) s.insert(pii(w[i], i));
    int ans = 0;
    for(int i = k; i < n; i++) {
        auto it = s.find_by_order(k/2);
        pii med = (pii) *it;
        ans = max(ans, med.first);
        s.erase(pii(w[i-k], i-k));
        s.insert(pii(w[i], i));
    }
    pii med = (pii) *s.find_by_order(k/2);
    ans = max(ans, med.first);
    printf("%d\n", ans);
}

