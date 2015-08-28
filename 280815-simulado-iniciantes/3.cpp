#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    pii inter[10004];
    int n, m, a, b, c, d;

    while(scanf("%d %d", &n, &m) && n != 0){
        for(int i = 0; i < n; i++){
            scanf("%d %d %d %d", &a, &b, &c, &d);
            inter[i] = make_pair(c, c+d);
        }

        sort(inter, inter + n);
        for(int i = 0; i < m; i++){
            int cont = 0;
            scanf("%d %d", &a, &b);
            for(int j = 0; j < n; j++){
                if(inter[j].first >= a && inter[j].second <= a+b)
                    cont++;
                else if(inter[j].first >= a && inter[j].first < a+b && inter[j].second > a+b)
                    cont++;
               else  if(inter[j].first < a && inter[j].second <= a+b && inter[j].second > a)
                    cont++;
               else  if(inter[j].first < a && inter[j].second > a+b)
                    cont++;

            }

            printf("%d\n", cont);
        }
    }
    
}
