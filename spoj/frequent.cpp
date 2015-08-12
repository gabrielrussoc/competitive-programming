#include <cstdio>
#include <map>
#include <algorithm>
#define MAXN 100005

using namespace std;

typedef pair<int,int> pii;

int n,q;
int in[MAXN];

struct node{
	int m;
	pii l;
	pii r;
} tree[4*MAXN];

void update(int pos, int k, int val, int l, int r){

	if(l == r){
		tree[k].m = 1;
		tree[k].l.first = val;
		tree[k].l.second = 1;
		tree[k].r.first = val;
		tree[k].r.second = 1;
	}
	else{
		int mid = (l+r)/2;

		if(mid <= pos)
			update(pos,2*k,val,l,mid);
		else
			update(pos,2*k+1,val,mid+1,r);

		if(tree[2*k].l.first == tree[2*k+1].r.first){
			tree[k].m = tree[2*k].m + tree[2*k+1].m;
			tree[k].l.first = in[l];
			tree[k].r.first = in[r];
			tree[k].l.second = 
		}
		
	}
}

int main(){
	
	scanf("%d %d",&n,&q);
	for(int i = 0; i < n; i++){
		scanf("%d",&in[i]);
		update(i,1,in[i],0,n-1);
	}

}