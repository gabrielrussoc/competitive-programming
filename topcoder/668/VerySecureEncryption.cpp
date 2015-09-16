#include <string>
#include <vector>
using namespace std;
class VerySecureEncryption {
	public:
	string encrypt(string message, vector <int> key, int K) {
	    int n = message.size();
            string tmp = message;
            while(K--){
                for(int i = 0; i < n; i++)
                    tmp[key[i]] = message[i];
                message = tmp;
            }       
            return message; 
	}
};
