#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
//////////////0123456789
const int N = 10004;
const int modn = 1000000007;


struct t {
    string nome;
    int score, reg;
    t () {}
    t (int a, int b, string c) : reg(a) , score (b) , nome(c) {} 
};

vector<t> v;
string s;
int x, y;
int freq[10004],n,m;

bool comp (t a, t b) {
    if(a.reg == b.reg) {
        return a.score > b.score;
    }
    return a.reg < b.reg;
}

int main() {
    scanf("%d %d",&n,&m);
    for(int i = 0; i < n; i++) {
        cin >> s >> x >> y;
        v.pb(t(x,y,s)); 
        freq[x]++;
    }
    sort(v.begin(), v.end(), comp);
    
    int i = 0;
    while(i < n) {
        if(freq[v[i].reg] > 2) {
            if(v[i+1].score == v[i+2].score) puts("?");
            else cout << v[i].nome << " " << v[i+1].nome << endl;
        }
        else cout << v[i].nome << " " << v[i+1].nome << endl;
        i += freq[v[i].reg];
    }
}

