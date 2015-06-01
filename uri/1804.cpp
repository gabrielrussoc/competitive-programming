#include <cstdio>
#include <algorithm>

#define N 100005

using namespace std;

int tree[4*N];

void update(int node, int ind, int lo, int hi, int val){

	if(lo == hi)
		tree[node] = val;

	else{
		int mid = (lo + hi)/2;

		if(mid >= ind)
			update(2*node, ind, lo, mid, val);
		else
			update(2*node+1, ind, mid+1, hi, val);

		tree[node] = tree[2*node] + tree[2*node+1];

	}
}

int sum(int node, int lo, int hi, int l, int u){

	int mid = (lo + hi)/2;

	if(lo >= l && hi <= u)
		return tree[node];

	else if(lo > u || hi < l)
		return 0;

	else
		return sum(2*node, lo, mid, l, u) + sum(2*node+1,mid+1,hi,l,u);

}


int main(){
	
	int n, val;

	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		scanf("%d",&val);
		update(1,i,0,n-1,val);
	}

	char c;

	while(scanf(" %c %d",&c,&val) != EOF){
		if(c == '?'){
			printf("%d\n",sum(1,0,n-1,0,val-2));
		}
		else
			update(1,val-1,0,n-1,0);


	}


}