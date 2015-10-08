#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int tree[4*N];
map<int,int> m;
int freq[N], ff[N], in[N];
int n, q, num;

void build(int no, int l, int r, int i) {
    if(l == r) {
        tree[no] = freq[i];
    }
    else {
        int mid = (l+r)/2;
        if(i <= mid) build(2*no,l,mid,i);
        else build(2*no+1,mid+1,r,i);
        tree[no] = max(tree[2*no],tree[2*no+1]);
    }
}

int query(int ini, int fim, int no, int l, int r) {
    if(l > fim || r < ini) return 0;
    if(l >= ini && r <= fim) return tree[no];
    int mid = (l+r)/2;
    return max(query(ini,fim,2*no,l,mid),query(ini,fim,2*no+1,mid+1,r));
}

int main() {
    while(scanf("%d",&n) && n != 0) {
        scanf("%d",&q);
        m.clear();
        memset(freq,0,sizeof freq);
        int k = 1;
        for(int i = 0; i < n; i++){
            scanf("%d",&num);
            if(!m[num]) m[num] = k++;
            num = m[num];
            in[i+1] = num;
            freq[num]++;
            if(freq[num] == 1) ff[num] = i+1;
        }
        for(int i = 1; i < k; i++) {
            build(1,1,k-1,i);
        }
        int a,b;
        for(int i = 0; i < q; i++) {
            scanf("%d %d",&a,&b);
            if(in[a] == in[b]) printf("%d\n",b-a+1);
            else {
            int maxi = max(freq[in[a]]-a+ff[in[a]], b-ff[in[b]]+1);
            if(in[a] + 1  == in[b]){
                printf("%d\n",maxi);
            }
            else {
                printf("%d\n",max(maxi,query(in[a]+1,in[b]-1,1,1,k-1)));
            }
            }
        }
    }
}