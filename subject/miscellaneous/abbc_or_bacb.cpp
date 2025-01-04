#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.size();

    int a = 0;

    int impossible = n + 1;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'A'){
            a++;
            curr++;
        } 
        else{
            impossible = min(impossible, curr);
            curr = 0;
        }
    }    
    impossible = min(impossible, curr);
    
    cout << a - impossible << endl;
}

int main(){    
    int t;
    cin >> t;
    while(t--) solve();
}