#include <bits/stdc++.h>

using namespace std;

int v[36], aux[36];
vector<int> f;

void flip(int k){
	int j = 0;
	for(int i = k-1; i >= 0; i--)
		aux[j++] = -v[i];

	for(int i = 0; i < k; i++)
		v[i] = aux[i];
}

int main(){
	
	int n,m;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&m);
		for(int j = 0; j < m; j++){
			scanf("%d",&v[j]);
		}
		bool ok = false;
		while(!ok){
			int b = 0;
			int ib;
			for(int j = 0; j < m; j++){
				if(abs(v[j]) > b && j+1 != v[j]){
					b = v[j];
					ib = j;
				}
			}
			//cout << b << endl;
			if(b == 0) ok = true;
			else {
				if(ib == 0) {
					if(v[ib] > 0 && v[ib] != 1){
						v[ib] = -v[ib];
						f.push_back(1);
					}
					if(v[ib] != 1){
						f.push_back(-v[ib]);
						flip(-v[ib]);
					}
				}
				else {
					f.push_back(ib+1);
					flip(ib+1);
				}
			}
		}
		printf("%d %d",i+1,f.size());
		for(int j = 0; j < f.size(); j++)
			printf(" %d",f[j]);
		printf("\n");
		f.clear();
	}


}