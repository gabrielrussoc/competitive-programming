#include <stdio.h>
#include <set>
#include <limits.h>
using namespace std;

int m, n;
int a[30004], u[30004];

int main(){
    scanf("%d %d",&m,&n);
    multiset<int> s;
    multiset<int>::iterator it;
    s.insert(INT_MAX);
    it = s.begin();
    for(int i = 0; i < m; i++) scanf("%d",a+i);
    for(int i = 0; i < n; i++) scanf("%d",u+i);

    int k = 0;
    for(int i = 0; i < n; i++){
        while(s.size() < u[i]+1) {
            s.insert(a[k++]);
            if(a[k-1] < *it) it--; 
        }
        printf("%d\n",*it);
        it++;
    }

}
