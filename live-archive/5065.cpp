#include <cstdio>
#include <algorithm>
#include <set>
#define pic pair<char,char>
#define ff first
#define ss second
using namespace std;

pic gf[29];
pic bf[29];
pic all[60];

int num(char x){
    if(x == 'T') return 10;
    if(x == 'J') return 11;
    if(x == 'Q') return 12;
    if(x == 'K') return 13;
    return x-'0';
}

int naipe(char x){
    if(x == 'D') return 0;
    if(x == 'C') return 1;
    if(x == 'H') return 2;
    return 3;
}

bool comp (pic x, pic y) {
    if (x.ff == y.ff){
        return naipe(x.ss) < naipe(y.ss);
    }
    else
        return num(x.ff) < num(y.ff);

}

char letra(int i){
    if(i > 7){
        if(i == 8) return 'T';
        if(i == 9) return 'J';
        if(i == 10) return 'Q';
        if(i == 11) return 'K';
        if(i == 12) return 'A';
    }
    return (i+2) + '0';
}

void gfcards(){
    for(int i = 0; i < 13; i++){
        all[4*i] = make_pair(letra(i),'D');
        all[4*i+1] = make_pair(letra(i),'C');
        all[4*i+2] = make_pair(letra(i),'H');
        all[4*i+3] = make_pair(letra(i),'S');
    }

}

void deleta(int i){

    for(int j = i; j < 25; j++)
        bf[j] = bf[j+1];

}

bool ntem(pic x){
    for(int i = 0; i < 26; i++)
        if(x == bf[i]) return false;
    return true;
}

int main () {
    int n;
    char c, num;
    
    scanf ("%d", &n);
    
    while (n--) {
        gfcards();
        for (int i = 0; i < 26; i++) {
            scanf (" %c %c", &num, &c);
            bf[i] = make_pair(num,c);
        }
        sort(bf,bf+26,comp);
        sort(all,all+52,comp);
        int j = 0, k = 0;
        for(int i = 0; i < 52; i++){
            if(ntem(all[i])) gf[j++] = all[i];
        }
        int ans = 0;
        k = 26;
        while(k){
            pic x = gf[26-k];
            int i;
            for(i = 0; i < k; i++)    
                if(comp(x,bf[i]))
                    break;
            if(i != k){
                ans++;
                deleta(i);
            }
            else deleta(0);
            k--;   
        }
        printf("%d\n",ans);       
        
    }
}

