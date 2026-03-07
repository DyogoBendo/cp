#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())


pair<vector<int>, vector<string>> calc(){
    vector<int>dp(60), dp2(60);
    vector<string> dp_ans(60), dp_ans2(60);
       
    priority_queue<tuple<int, string, int>, vector<tuple<int, string, int>>, greater<tuple<int, string, int>>> pq;

    pq.push({0, "", 0});

    while(!pq.empty()){
        auto [tam, tex, m] = pq.top(); pq.pop();        
        if(dp[m]) continue;


        dp[m] = 1;
        dp_ans[m] = tex;

        for(int i = 0; i < 6; i++){
            char c = 'A' + i;

            int al = 10+i;
            int ar = (16 * al) % 60;                
            int r = (ar + m) % 60;                

            pq.push({tam+1, tex+c, r});                                          
        }        
    }    

    return make_pair(dp, dp_ans);
}

string get_min(string a, string b){
    if(a == "") return b;
    if(b == "") return a;
    if(sz(a) < sz(b)) return a;
    if(sz(b) < sz(a)) return b;

    if(a < b) return a;
    return b;
}

void solve(){
    string s;
    cin >> s;

    int curr = 0;
    int p = 1;    
    for(int i = sz(s) - 1; i >= 0; i--){
        char c = s[i];
        int x = (c - 'A') + 10;
        curr += (x*p) % 60;
        curr %= 60;
        p*= 16;
        p %= 60;
    }

    if(curr == 0){
        cout << "OK" << endl;
        return;
    }
    

    int lst = s.back() - 'A' + 10;    
    int diff = (16 * lst - lst + 60 ) % 60;
    
    auto [dp, dp_ans] = calc();

    string ans = dp_ans[60 - curr];

    curr = (curr + diff) % 60;

    for(int i = 0; i < 6; i++){
        int x = (60 - (curr + 10 + i) + 60) % 60;        

        if(dp[x]){
            string s2 = dp_ans[x];
            char c2 = 'A' +i;
            s2 +=  c2;            
            sort(s2.begin(), s2.end());
            ans = get_min(ans, s2);
        }        
    }

    cout << ans << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    //cin >> cases;
    for (int i=0; i<cases; i++) solve();
}