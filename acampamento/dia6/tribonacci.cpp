#include <cstdio>
typedef long long ll;
#define MOD 1000000009

using namespace std;

struct Matrix {
	ll m[3][3];
} I = {1,0,0,0,1,0,0,0,1},
R = {1,1,1,1,0,0,0,1,0},
O = {0,0,0,0,0,0,0,0,0};


void mult(Matrix &x, Matrix &y){
	Matrix t = O;

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0; k < 3; k++)
				t.m[i][j] += (x.m[i][k] * y.m[k][j])%MOD;
	
	x = t;
}

Matrix exp(ll n){
	
	Matrix x = I;
	Matrix y = R;
	while(n > 0){
		if(n%2 == 1)
			mult(x,y);
		n /= 2;
		mult(y,y);
	}

	return x;
}

int main(){
	
	Matrix ans;
	ll n;

	while(scanf("%lld",&n), n != 0){
		if(n == 1)
			printf("0\n");
		else if(n == 2)
			printf("1\n");
		else if(n == 3)
			printf("2\n");
		else{
			ans = exp(n-3);
			printf("%lld\n",(2*ans.m[0][0] + ans.m[0][1])%MOD);
		}
	}
}