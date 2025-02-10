#include <bits/stdc++.h>

using namespace std;

int qtd3 = 0;
int qtd2 = 0;

int calc(string s){
    int ans = 0;
    string a;
    for (char c : s)
    {        
        if(c == '2') qtd2 ++;
        if(c == '3') qtd3 ++;
        ans += (c - '0');
    }    
    
    return ans % 9;
}

int v[] = {0, 4, 8, 3, 7, 2, 6, 1, 5};

void solve(){
    qtd2 = 0;
    qtd3 = 0;    

    string s;
    cin >> s;

    int m = calc(s);

    int needed2 = v[m];    

    while(qtd3 && needed2 >= 3){
        needed2 -= 3;
        qtd3 --;
    }

    while(qtd2 && needed2 > 0){
        needed2 --;
        qtd2 --;
    }

    if(needed2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}