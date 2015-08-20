#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

struct pista {
	int i;
	int j;
	int d;
} v[105];

int mdis(int x1, int y1, int x2, int y2){
	return abs(x2-x1) + abs (y2-y1);
}

int main(){

	int n,k;
	cin >> n >> k;
	for(int i = 0; i < k; i++)
		cin >> v[i].i >> v[i].j >> v[i].d;

	int ans = 0;
	int ai, aj;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			bool ok = true;
			for(int p = 0; p < k; p++){
				if(mdis(v[p].i,v[p].j,i,j) != v[p].d) ok = false;
				
			}
			if(ok){ ans++;
			ai = i; aj = j;}
			if(ans > 1) break;
		}

	if(ans == 1) cout << ai << ' ' << aj << endl;
	else cout << -1 << ' ' << -1 << endl;

}
