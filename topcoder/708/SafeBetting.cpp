#include <bits/stdc++.h>
using namespace std;

class SafeBetting {
public:
    int minRounds( int a, int b, int c ) {
        int ans = 0;
        while (b < c) {
            for(int k = b; k >= 0; k--) {
                if(b - k >= a) {
                    b += k;
                    break;
                }
            } 
            ans++;
        }
        return ans;
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
	
	int verify_case(int casenum, const int &expected, const int &received, std::clock_t elapsed) { 
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
			std::cerr << "    Expected: " << expected << std::endl; 
			std::cerr << "    Received: " << received << std::endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int a                     = 15;
			int b                     = 20;
			int c                     = 48;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = SafeBetting().minRounds(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int a                     = 10;
			int b                     = 400;
			int c                     = 560;
			int expected__            = 1;

			std::clock_t start__      = std::clock();
			int received__            = SafeBetting().minRounds(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int a                     = 5;
			int b                     = 7;
			int c                     = 21;
			int expected__            = 3;

			std::clock_t start__      = std::clock();
			int received__            = SafeBetting().minRounds(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int a                     = 5;
			int b                     = 7;
			int c                     = 22;
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = SafeBetting().minRounds(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int a                     = 17;
			int b                     = 30;
			int c                     = 1000;
			int expected__            = 7;

			std::clock_t start__      = std::clock();
			int received__            = SafeBetting().minRounds(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SafeBetting().minRounds(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SafeBetting().minRounds(a, b, c);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int a                     = ;
			int b                     = ;
			int c                     = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = SafeBetting().minRounds(a, b, c);
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
