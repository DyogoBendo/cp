#include <bits/stdc++.h>

using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    
    if(a == b){
        if(c % 2){
            cout << "First" << endl;
        } else{
            cout << "Second" << endl;
        }
    }
    else if(a > b){
        cout << "First" << endl;
    } else{
        cout << "Second" << endl;
    }
    
}

int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
}