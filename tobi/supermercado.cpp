#include <algorithm>
#include <iostream>
using namespace std;

int main(){

	int s, tc = 1;
	int x[1004], y[1004];
	while(cin >> s, s!= 0){
		for(int i = 0; i < s; i++)
		   cin >> x[i] >> y[i];
		sort(x,x+s);
		sort(y,y+s);
		cout << "Teste " << tc++ << endl;
		cout << x[s/2] << ' ' << y[s/2] << endl << endl; 	
	}

}
