#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main(){

    vector<pair<int,int> > pos;
    vector<pair<int,int> > neg;

    int n;
    scanf("%d",&n);
    
    for(int i = 0; i < n; i++){
        int a,x;
        scanf("%d %d",&x,&a);
        if(x > 0)
            pos.pb(make_pair(x,a));
        else
            neg.pb(make_pair(-x,a));
    } 
    
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    
    int tpos, tneg;
    tpos = pos.size();
    tneg = neg.size();
    int mini = min(tpos,tneg);
    
    int ans = 0;
    if(tpos == tneg)
        for(int i = 0; i < n/2; i++)
            ans += neg[i].second + pos[i].second;
            
    else if(tpos > tneg){
        for(int i = 0; i < mini+1; i++)
            ans += pos[i].second;
        for(int i = 0; i < mini; i++)
            ans += neg[i].second;      
    }
    else if(tneg > tpos){
        for(int i = 0; i < mini+1; i++)
            ans += neg[i].second;
        for(int i = 0; i < mini; i++)
            ans += pos[i].second;
    }
    
    cout << ans << endl;
    
    


}
