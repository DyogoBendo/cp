#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;    

    int possible = n - 1;

    for (int i = 0; i < n - 2; i++)
    { 
        if(s[i] == s[i + 2]) possible --;
    }
    
    cout << possible << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}