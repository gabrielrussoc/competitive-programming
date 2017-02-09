#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3002;
ll memo[N][N];
string s;
const ll MOD = 1000000007;

class PalindromicSubseq2 {
public:

    ll dp(int i, int j) {
        if(i < 0 || j >= s.length()) return 0;
        ll &me = memo[i][j];
        if(me != -1) return me;
        if(s[i] == s[j]) me = (dp(i-1, j) + dp(i, j+1) + 1) % MOD; 
        else me = ((dp(i-1, j) + dp(i, j+1)) % MOD + MOD - dp(i-1, j+1)) % MOD;
        return me % MOD;
    }

    int solve( string s ) {
        memset(memo, -1, sizeof memo);
        int n = s.length();
        ::s = s;
        ll ans = 0;
        for(int i = 0; i < n; i++) ans ^= ll((i+1) * (1+dp(i-1, i+1))) % MOD;
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
			string s                  = "axbcba";
			int expected__            = 31;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubseq2().solve(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "eeeee";
			int expected__            = 14;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubseq2().solve(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "tcoct";
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubseq2().solve(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "zyzyzzzzxzyz";
			int expected__            = 221;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubseq2().solve(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s                  = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
			int expected__            = 1044407608;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubseq2().solve(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string s                  = "aba";
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubseq2().solve(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			string s                  = "aaa";
			int expected__            = 4;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubseq2().solve(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			string s                  = ;
			int expected__            = ;

			std::clock_t start__      = std::clock();
			int received__            = PalindromicSubseq2().solve(s);
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
