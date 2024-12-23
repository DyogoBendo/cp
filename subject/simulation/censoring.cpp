#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("censor");

   string s, t;
   cin >> s;
   cin >> t;

   int tl = t.size();

    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        ans += s[i];
        if(ans.size() > tl && ans.substr(ans.size() - tl) == t){
            ans.resize(ans.size() - tl);
        }
    }
    
   cout << ans << endl;
    
}