#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 1000006;
int a[N], n;
ll lmn[N], lmx[N], rmn[N], rmx[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a+i);
    
    stack<int> mn, mx;
    for(int i = 0; i < n; i++) {
        while(!mn.empty() && a[mn.top()] >= a[i]) mn.pop();
        while(!mx.empty() && a[mx.top()] <= a[i]) mx.pop();
        lmn[i] = mn.empty() ? i+1 : i - mn.top();
        lmx[i] = mx.empty() ? i+1 : i - mx.top();
        mn.push(i);
        mx.push(i);
    }
    while(!mn.empty()) mn.pop();
    while(!mx.empty()) mx.pop();
    for(int i = n-1; i >= 0; i--) {
        while(!mn.empty() && a[mn.top()] > a[i]) mn.pop();
        while(!mx.empty() && a[mx.top()] < a[i]) mx.pop();
        rmn[i] = mn.empty() ? n-i : mn.top() - i;
        rmx[i] = mx.empty() ? n-i : mx.top() - i;
        mn.push(i);
        mx.push(i);
    }

    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans += ll(a[i]) * (lmx[i]*rmx[i] - lmn[i]*rmn[i]);
    printf("%lld\n", ans);
}

