#include <bits/stdc++.h>

using namespace std;

string s;
int n;
bool check(int i){
    if(i >= n -3 || i < 0) return false;
    return (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0');
}

void solve(){
    cin >> s;

    // preciso achar todas os intervalos que possuem 1100. Quando eu faço a modificação, apenas quatro intervalos são alterados
    // se eu altero a posição i, os intervalos que podem ter sido modificados são: 
    // i i + 1 i + 2 i + 3
    // i - 1 i  i + 1 i + 2
    // i - 2 i - 1
    // i - 3 ... i

    set<int> start_pos;
    n = s.length();

    for (int i = 0; i < n - 3; i++)
    {
        if(check(i)){
            start_pos.insert(i);
        }
    }    

    int q;
    cin >> q;
    while(q--){
        int i;
        char v;
        cin >> i >> v;
        i--;
        if(check(i) && v == '0'){
            start_pos.erase(i);
        }
        if(check(i - 1) && v == '0'){
            start_pos.erase(i - 1);
        }
        if(check(i - 2) && v == '1'){
            start_pos.erase(i - 2);
        }
        if(check(i - 3) && v == '1'){
            start_pos.erase(i - 3);
        }        

        s[i] = v;

        for (int j = 0; j < 4; j++)
        {
            if(check(i - j)) start_pos.insert(i - j);
        }
    
        if(!start_pos.empty()){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}