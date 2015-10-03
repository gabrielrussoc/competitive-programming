#include <cstdio>
#include <cstring>
using namespace std;

int n,x1,x2,y1,y2,num, bit[1030][1030], in[1030][1030];
char s[17];

void update(int idx, int idy, int val){
    for(int i = idx; i <= n; i += i&-i)
        for(int j = idy; j <= n; j += j&-j)
            bit[i][j] += val;
}

int query(int idx, int idy){
    int sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        for(int j = idy; j > 0; j -= j&-j)
            sum += bit[i][j];
    return sum;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                bit[i][j] = in[i][j] = 0;
        while(scanf(" %s",s) && strcmp(s,"END")){
            if(!strcmp(s,"SET")){
                scanf("%d %d %d",&x1,&y1,&num);
                x1++, y1++;
                update(x1,y1,num-in[x1][y1]);
                in[x1][y1] = num;
            }
            else {
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                x1++,x2++,y1++,y2++;
                printf("%d\n",query(x2,y2) + query(x1-1,y1-1) - query(x1-1,y2) - query(x2,y1-1));
            }
        }
    }
}
