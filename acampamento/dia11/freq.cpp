#include <bits/stdc++.h>
#define N 100005
using namespace std;


int tree[4*N];
int n,q;
map<int,int> m;

void build(int node, int val, int i, int l, int u){

	if(l == u) tree[node] = val;
	else{
		int mid = (l+u)/2;
		if(i <= mid)
			build(2*node,val,i,l,mid);
		else
			build(2*node+1,val,i,mid+1,u);

		int f1,f2;
		f1 = m[tree[2*node]];
		f2 = m[tree[2*node+1]];
		if(f1 > f2)
			tree[node] = tree[2*node];
		else
			tree[node] = tree[2*node+1]; 
	}
}

int query(int node, int l, int u, int d, int e){

	


}


int main(){
	
	scanf("%d %d",&n,&q);
	int cont = 0;
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d",&a);
		if(m.insert(make_pair(a,1)).second) cont++;
		else m[a]++;
	}
	map<int,int>::iterator it;
	int i = 0;
	int k = m.size();
	for(it = m.begin(); it != m.end(); it++){
		build(1,it -> first,i,0,k);
		i++;
	}



}