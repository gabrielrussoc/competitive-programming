#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class OrAndSumEasy {
public:
    string isPossible( long long pairOr, long long pairSum ) {
        bool carry = 0;
        ll A = 0, B = 0;
        for(ll i = 0; i < 62; i++) {
            ll q = (1ll<<i);
            bool por = pairOr & q;
            bool ps = pairSum & q;
            if(!por) {
                if(ps) {
                    if(carry) carry = 0;
                    else return "Impossible";
                } else {
                    if(carry) return "Impossible";
                }
            } else {
                if(ps) {
                    if(carry) {
                        A |= q;
                        B |= q;
                    } else {
                        B |= q;   
                    }
                } else {
                    if(carry) {
                        B |= q;
                    } else {
                        A |= q;
                        B |= q;
                        carry = 1;
                    }
                }
            }
        }
        if(carry) A |= (1ll<<62);
        return (A + B == pairSum && ((A | B) == pairOr)) ? "Possible" : "Impossible";
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
			long long pairOr          = 7;
			long long pairSum         = 11;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = OrAndSumEasy().isPossible(pairOr, pairSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long pairOr          = 11;
			long long pairSum         = 7;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = OrAndSumEasy().isPossible(pairOr, pairSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long pairOr          = 999799115789631487LL;
			long long pairSum         = 999999999999999999LL;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = OrAndSumEasy().isPossible(pairOr, pairSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long pairOr          = 1;
			long long pairSum         = 100;
			string expected__         = "Impossible";

			std::clock_t start__      = std::clock();
			string received__         = OrAndSumEasy().isPossible(pairOr, pairSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long pairOr          = 0;
			long long pairSum         = 0;
			string expected__         = "Possible";

			std::clock_t start__      = std::clock();
			string received__         = OrAndSumEasy().isPossible(pairOr, pairSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long pairOr          = ;
			long long pairSum         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = OrAndSumEasy().isPossible(pairOr, pairSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long pairOr          = ;
			long long pairSum         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = OrAndSumEasy().isPossible(pairOr, pairSum);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long pairOr          = ;
			long long pairSum         = ;
			string expected__         = ;

			std::clock_t start__      = std::clock();
			string received__         = OrAndSumEasy().isPossible(pairOr, pairSum);
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
