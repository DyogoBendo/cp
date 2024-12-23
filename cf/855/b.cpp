#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> lowercase(26, 0);    
    vector<int> uppercase(26, 0);    

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if(c >= 'a'){
            lowercase[c - 'a'] ++;
        } else{            
            uppercase[c - 'A'] ++;
        }
    }
    
    int r = 0;
    for (int i = 0; i < 26; i++)
    {
        r += min(lowercase[i], uppercase[i]);
        int diff = abs(lowercase[i] - uppercase[i]) / 2;

        if(diff <= k) {
            k -= diff;
            r += diff;
        } else{
            r+= k;
            k = 0;
        }
    }
    
    cout << r << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}