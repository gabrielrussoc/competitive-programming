#include <cstdio>

typedef unsigned long long ull;

using namespace std;

const int modn = 1000000;

struct Matrix {
	ull m[2][2];
} I = {1,0,0,1}, O = {0,0,0,0}, R = {0,0,1,0};

void mult(Matrix &x, Matrix &y){
	Matrix t = O;
	for(int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			for(int k = 0; k < 2; k++)
				t.m[i][j] = (t.m[i][j] + x.m[i][k] * y.m[k][j])%modn;

	x = t;
}


Matrix solve(ull n){
	Matrix x = I;
	Matrix y = R;
	while(n){
		if(n&1)
			mult(x,y);
		mult(y,y);
		n /= 2;
	}
	return x;
}

int main(){
	ull n,k,l;
	
	while(scanf("%llu %llu %llu",&n,&k,&l) != EOF){ 
		k %= modn;
		l %= modn;
		R.m[0][0] = k;
		R.m[0][1] = l;
		n /= 5;
		if(n == 1){
			printf("%.6llu",l%1000000);
		}
		else if(n == 2){
			printf("%.6llu",(l + k*k)%1000000);
		}
		else {
			Matrix ans = solve(n-2);
			printf("%.6llu",(ans.m[0][0]*(l+k*k)+ans.m[0][1]*k)%1000000);
		}
		printf("\n");
	}
}
