#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;

    cin >> s;

    set<char> even;
    set<char> odd;

    for (int i = 0; i < n; i++)
    {
        if(i%2){
            if(even.find(s[i]) != even.end()){
                cout << "NO" << endl;
                return;
            }
            odd.insert(s[i]);
        } else{
            if(odd.find(s[i]) != odd.end()){
                cout << "NO" << endl;
                return;
            }
            even.insert(s[i]);
        }
    }

    cout << "YES" << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}