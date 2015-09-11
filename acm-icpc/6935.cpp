#include <cstdio>

using namespace std;

long long mdc(long long a, long long b){
    if(b==0)return a;
    return mdc(b,a%b);
}

long long v[100005];
char x[100005];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long n, tw,tb,sw,sb, g;
        tw = tb = sw = sb = 0;
        char c;
        scanf("%lld",&n);
        long long ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%lld %c",&g,&c);
            v[i] = g;
            x[i] = c;
            if(c == 'B') tb += g;
            else tw += g;
        }
        if(tw == 0) ans = tb;
        else if(tb == 0) ans = tw;
        else{
            long long m = mdc(tb,tw);
            tb /= m;
            tw /= m;
            for(int i = 0; i < n; i++){
                if(x[i] == 'B') {
                    if((tb*sw)%tw == 0){
                        long long k = (tb*sw)/tw - sb;
                        if(k > 0 && k <= v[i]) ans++; 
                    }
                    sb += v[i];

                }
                else{
                    if((tw*sb)%tb == 0){
                        long long k = (tw*sb)/tb - sw;
                        if(k > 0 && k <= v[i]) ans++; 
                    }
                    sw += v[i];
                }    
            }
        }

        printf("%d\n",ans);
    }
}
