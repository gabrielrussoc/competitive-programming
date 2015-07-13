#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

ll p9[10];
ll p10[10];

int main(){
	int n, q, aux;

	p9[0] = 1;
	p10[0] = 1;

	for(int i = 1; i <= 9; i++){
		p9[i] = 9 * p9[i-1];
		p10[i] = 10 * p10[i-1];
		//cout << p10[i] << endl;
	}

	while(cin >> n, n != 0){
		aux = n;
        int t = 0;
	    while(aux){
		    t++; aux/=10;
	    }
	    t--;

	    int res = 0;
	    aux = n;
	
	    while(t > 0){
	    	q = aux/p10[t];
		    //cout << q << ' ' <<  aux << endl;
		    if(q > 4){
			    q--;
			    res += p10[t];
		    }

		    res += q*(p10[t] - p9[t]);
		    aux = aux % p10[t];
		    t--;
	    }	

	    if(aux > 4) res++;

	    cout << n << ": " <<  n-res << endl;

	 }

}
