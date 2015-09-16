#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

pii v[3003];

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        for(int i = 0; i < n; i++){
            int a,b;
            scanf("%d %d",&a,&b);
            v[i] = mp(a,b);
        }
        sort(v,v+n);
        int ans = 0;
        for(int i = 1; i < n; i++){
            int mini = INT_MAX, maxi = INT_MIN;
            for(int j = i-1; j >= 0; j--){
                if(v[j].ss > v[i].ss){
                    if(v[j].ss < mini){
                        ans++;
                        mini = v[j].ss;
                    }
                }
                if(v[j].ss < v[i].ss){
                    if(v[j].ss > maxi){
                        ans++;
                        maxi = v[j].ss;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
