#include <bits/stdc++.h>

using namespace std;

int check(string &s){
    vector<int> cnt_l(26, 0);
    vector<int> cnt_r(26, 0);
    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        cnt_r[s[i] - 'a']++;
    }

    cout << "s: " << s << endl;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        cnt_l[c - 'a'] ++; 
        cnt_r[c - 'a'] --;

        bool possible = true;
        for (int j = 0; j < 26; j++)
        {
            if(cnt_l[j] < cnt_r[j]) possible = false;
        }
        
        if(possible) return i + 1;
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

    cout << "ans1: " << ans << endl;
    ans = min(ans, check(s1));
    cout << "ans2: " << ans << endl;


    cout << ans << endl;
}

signed main(){
    int t;
    cin >> t;

    while(t--) solve();
}