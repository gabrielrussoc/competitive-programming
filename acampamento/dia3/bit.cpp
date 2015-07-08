#include <iostream>

using namespace std;

int main(){

	int x = 0;
	int n;
	cin >> n;

	while(n--){
		char a,b,c;
		cin >> a >> b >> c;
		if(b == '+')
			x++;
		else
			x--;
	}
	cout << x << endl;
}
