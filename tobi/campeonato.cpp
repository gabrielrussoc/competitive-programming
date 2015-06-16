#include <iostream>

using namespace std;

int main(){
	
	int cv,ce,cs,fv,fe,fs;
	cin >> cv >> ce >> cs >> fv >> fe >> fs;

	int pc = cv*3 + ce;
	int pf = fv*3 + fe;

	if(pc > pf)
		cout << 'C';
	else if(pf > pc)
		cout << 'F';
	else{

		if(cs > fs)
			cout << 'C';
		else if(fs > cs)
			cout << 'F';
		else
			cout << '=';
	}

	cout << endl;


}