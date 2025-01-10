// https://codeforces.com/contest/318/problem/B
// strings

#include <bits/stdc++.h>

using namespace std;

#define int long long

bool is_equal(string &s, string &w, int i){
    string sub = s.substr(i, 5);
    return sub == w;
}

signed main(){
    string s;
    cin >> s;

    int n = s.size();

    int heavy_appearences = 0;
    int ans = 0;

    string m = "metal";
    string h = "heavy";

    for (int i = 0; i < n - 4; i++)
    {
        if (is_equal(s, m, i)){
            ans += heavy_appearences;
        } else if(is_equal(s, h, i)){
            heavy_appearences ++;
        }
        
    }

    cout << ans << endl;
    
}