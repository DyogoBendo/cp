#include <bits/stdc++.h>

using namespace std;

int check(string &s){
    int n = s.size();
    vector<vector<int>> cnt_l(n + 1, vector<int>(26, 0));
    vector<vector<int>> cnt_r(n + 1, vector<int>(26, 0));    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int x = s[i] - 'a';
            cnt_l[i + 1][j] = cnt_l[i][j] + (x == j);
        }
                
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            int x = s[i] - 'a';
            cnt_r[i][j] = cnt_r[i + 1][j] + (x == j);
        }                
    }
    
    bool found = false;
    for (int i = n/2 - 1; i >= 0; i--)
    {

        if(s[i] != s[n - i - 1]){

            bool possible = true;            

            for (int j = 0; j < 26; j++)
            {
                if(cnt_l[i + 1][j] < cnt_r[n - i][j]) possible = false;                
            }
            
            if(possible) return i + 1;
            else break;
        } 
    }
    
    
    for (int i = 0; i < n; i++)
    {
        char c = s[i];        
        
        bool possible = true;
        for (int j = 0; j < 26; j++)
        {
            if(cnt_l[i][j] < cnt_r[i][j]) possible = false;                        
        }        
        
        if(possible) return i;
    }
    
    return n;
}

void solve(){
    string s;
    cin >> s;

    int n = (int) s.size();

    int start = 0;

    for (int i = 0; i < n/2; i++)
    {
        if(s[i] == s[n - i - 1]) start ++;
        else break;
    }
    if(start == n/2){
        cout << 0 << endl;
        return;
    }

    string s1 = s.substr(start, n - 2*start);
    
    int ans = check(s1);
    reverse(s1.begin(), s1.end());
    
    ans = min(ans, check(s1));    


    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t--) solve();
}