#include <bits/stdc++.h>
using namespace std;

class SubstitutionCipher {
public:
    string decode( string a, string b, string y ) {
        int v[30], x[30];
        for(int i = 0; i < 30; i++) v[i] = x[i] = -1;
        for(int i = 0; i < a.length(); i++)
            v[b[i]-'A'] = a[i]-'A';
        int cont = 0;
        for(int i = 0; i < 26; i++) {
            if(v[i] == -1) cont++;
            else x[v[i]]++;
        }
        if(cont == 1){
            for(int i = 0; i < 26; i++) {
                if(v[i] == -1){
                    for(int j = 0; j < 26; j++)
                        if(x[j] == -1) {
                            v[i] = j;
                            break;
                        }
                    break;
                }
            }
        }

        string foo;
        for(int i = 0; i < y.length(); i++){
            if(v[y[i]-'A'] != -1) foo += v[y[i] -'A'] + 'A';
            else return "";
        }
        return foo;
    }
};

// BEGIN CUT HERE
#include <cstdio>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
namespace moj_harness {
	using std::string;
	using std::vector;
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				std::cerr << "Illegal input! Test case " << casenum << " does not exist." << std::endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			std::cerr << "No test cases run." << std::endl;
		} else if (correct < total) {
			std::cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << std::endl;
		} else {
			std::cerr << "All " << total << " tests passed!" << std::endl;
		}
	}
	
	int verify_case(int casenum, const string &expected, const string &received, std::clock_t elapsed) { 
		std::cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			std::sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		std::cerr << verdict;
		if (!info.empty()) {
			std::cerr << " (";
			for (size_t i=0; i<info.size(); ++i) {
				if (i > 0) std::cerr << ", ";
				std::cerr << info[i];
			}
			std::cerr << ")";
		}
		std::cerr << std::endl;
		
		if (verdict == "FAILED") {
			std::cerr << "    Expected: \"" << expected << "\"" << std::endl; 
			std::cerr << "    Received: \"" << received << "\"" << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string a                  = "CAT";
			string b                  = "DOG";
			string y                  = "GOD";
			string expected__         = "TAC";

			std::clock_t start__      = std::clock();
			string received__         = SubstitutionCipher().decode(a, b, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string a                  = "BANANA";
			string b                  = "METETE";
			string y                  = "TEMP";
			string expected__         = "";

			std::clock_t start__      = std::clock();
			string received__         = SubstitutionCipher().decode(a, b, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string a                  = "THEQUICKBROWNFOXJUMPSOVERTHELAZYHOG";
			string b                  = "UIFRVJDLCSPXOGPYKVNQTPWFSUIFMBAZIPH";
			string y                  = "DIDYOUNOTICESKIPPEDLETTER";
			string expected__         = "CHCXNTMNSHBDRJHOODCKDSSDQ";

			std::clock_t start__      = std::clock();
			string received__         = SubstitutionCipher().decode(a, b, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string a                  = ;
			string b                  = ;
			string y                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SubstitutionCipher().decode(a, b, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			string a                  = ;
			string b                  = ;
			string y                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SubstitutionCipher().decode(a, b, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string a                  = ;
			string b                  = ;
			string y                  = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = SubstitutionCipher().decode(a, b, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


#include <cstdlib>
int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(std::atoi(argv[i]));
	}
}
// END CUT HERE
