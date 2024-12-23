#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;

    cin >> n >> k;

    string s1;
    string s2;
    cin >> s1 >> s2;

    vector<int> c1 (26, 0);
    vector<int> c2(26, 0);

    for (int i = 0; i < n; i++)
    {
        c1[s1[i] - 'a'] ++;
        c2[s2[i] - 'a'] ++;
    }
    

    for (int i = 0; i < 26; i++)
    {        
        if(c1[i] != c2[i]){
            cout << "NO" << endl;
            return;
        }
    }
    
    vector<int> sw (n, 0);
    for (int i = 0; i < n - k; i++)
    {
        sw[i] ++;
        sw[i + k] ++;
        if(i + k + 1 < n){
            sw[i] ++;
            sw[i + k + 1] ++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(i == 0 && sw[i] == 1){
            if(s1[0] != s2[0] && s1[0] != s2[n - 1]){
                cout << "NO" << endl;
                return;
            }
        }
        if(sw[i] == 0){
            if(s1[i] != s2[i]){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}