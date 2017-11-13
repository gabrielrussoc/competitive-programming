#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 10;
int v[N];

int main() {
    int sum = 0;
    for(int i = 0; i < 6; i++) {
        scanf("%d", v+i);
        sum += v[i];
    }

    for(int i = 0; i < 6; i++)
        for(int j = i+1; j < 6; j++)
            for(int k = j+1; k < 6; k++) {
                int t1 = v[i] + v[j] + v[k];
                int t2 = sum - t1;
                if(t1 == t2) {
                    printf("YES");
                    return 0;
                }
            }

    printf("NO");
}

