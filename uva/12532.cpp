#include <cstdio>
#include <vector>
#include <algorithm>
#define N 100005

using namespace std;

int tree[4*N];

int prod(int node, int ini, int fim, int l, int u){

	if(ini >= l && fim <= u)
		return tree[node];

	if(ini > u || fim < l)
		return 1;

	else{
		int mid = (ini + fim)/2;
		return prod(2*node,ini,mid,l,u) * prod(2*node+1,mid+1,fim,l,u);
	}

}

int sign(int a){
	if (a > 0)
		return 1;
	if(a < 0)
		return -1;

	return 0;
}

void update(int ind, int val, int node, int ini, int fim){

	if(ini == fim)
		tree[node] = val;

	else{
		int mid = (ini + fim)/2;

		if(mid >= ind)
			update(ind, val, 2*node, ini, mid);
		else
			update(ind, val, 2*node+1,mid+1,fim);

		tree[node] = tree[2*node] * tree[2*node+1]; 

	}

}

int main(){


	int n, k, val, j, ind, ind1;
	char c;
	vector<char> v;

	while(scanf("%d %d",&n,&k) != EOF){

		v.clear();

		for(int i = 1; i <= n; i++){
			scanf("%d",&val);
			val = sign(val);
			update(i, val, 1, 1, n);
		}

		for(int i = 0; i < k; i++){
			scanf(" %c",&c);
			if(c == 'C'){
				scanf("%d %d",&ind,&val);
				val = sign(val);
				update(ind,val,1,1,n);
			}
			else{
				scanf("%d %d",&ind,&ind1);
				int tmp = prod(1,1,n,ind,ind1);
				if(tmp > 0)
					v.push_back('+');
				else if(tmp < 0)
					v.push_back('-');
				else
					v.push_back('0');
			}
		}

		for(int i = 0; i < v.size(); i++)
			printf("%c",v[i]);
		printf("\n");

	}



}
